//
//  Copyright (c) 2013 Click'nTap SRL. All rights reserved.
//

#import "TapBox2DView.h"

@implementation TapBox2DView

class QueryCallback : public b2QueryCallback {
public:
	QueryCallback(const b2Vec2& point) {
		m_point = point;
		m_fixture = NULL;
	}
	bool ReportFixture(b2Fixture* fixture) {
		b2Body* body = fixture->GetBody();
		if (body->GetType() == b2_dynamicBody) {
			bool inside = fixture->TestPoint(m_point);
			if (inside) {
				m_fixture = fixture;
				return false;
			}
		}
		return true;
	}
	b2Vec2 m_point;
	b2Fixture* m_fixture;
};

- (id)init {
  self = [super init];
  if (self) {
    world = new b2World( b2Vec2(0,-9.81), false);
    world->SetContinuousPhysics(true);
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    groundBody = world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    CGSize screenSize = CGSizeMake(768,1024);
    groundBox.SetAsEdge(b2Vec2(0,0), b2Vec2(screenSize.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
    groundBox.SetAsEdge(b2Vec2(0,screenSize.height/PTM_RATIO), b2Vec2(screenSize.width/PTM_RATIO,screenSize.height/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    groundBox.SetAsEdge(b2Vec2(0,screenSize.height/PTM_RATIO), b2Vec2(0,0));
    groundBody->CreateFixture(&groundBox,0);
    groundBox.SetAsEdge(b2Vec2(screenSize.width/PTM_RATIO,screenSize.height/PTM_RATIO), b2Vec2(screenSize.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
  }
  return self;
}

- (void)dealloc {
  delete world;
}

-(b2Body*)addPhysicalBodyForView:(UIView *)physicalView {
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	CGPoint p = physicalView.center;
	bodyDef.position.Set((p.x)/PTM_RATIO, (1024-p.y)/PTM_RATIO);
	bodyDef.userData = (__bridge void*)physicalView;
	b2Body *body = world->CreateBody(&bodyDef);
	b2CircleShape dynamicBox;
  dynamicBox.m_radius = physicalView.bounds.size.width/PTM_RATIO/2.0;
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 3.0f;
	fixtureDef.friction = 0.5f;
	fixtureDef.restitution = 0.8f;
	body->CreateFixture(&fixtureDef);
	body->SetType(b2_dynamicBody);
	physicalView.tag = (int)body;
  return body;
}

-(void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration {
	b2Vec2 gravity;
	gravity.Set( acceleration.x * 9.81 * 2,  acceleration.y * 9.81 * 2);
	world->SetGravity(gravity);
}

-(void)idle {
	int32 velocityIterations = 4;
	int32 positionIterations = 1;
	world->Step(1.0f/40.0f, velocityIterations, positionIterations);
	for (b2Body* b = world->GetBodyList(); b; b = b->GetNext()) {
		if (b->GetUserData() != NULL) {
			UIView *oneView = (__bridge UIView *)b->GetUserData();
			CGPoint newCenter = CGPointMake(b->GetPosition().x * PTM_RATIO, self.bounds.size.height - b->GetPosition().y * PTM_RATIO);
			oneView.center = newCenter;
			CGAffineTransform transform = CGAffineTransformMakeRotation(- b->GetAngle());
			oneView.transform = transform;
		}
	}
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
	UITouch *touch = [[event allTouches] anyObject];
	CGPoint touchZone = [touch locationInView:self];
  touchZone.x = touchZone.x;
  touchZone.y = 1024-touchZone.y;
	b2Vec2 p;
	p.Set(touchZone.x/PTM_RATIO, touchZone.y/PTM_RATIO);
	if (mouseJoint != nil) {
		return;
	}
	b2AABB aabb;
	b2Vec2 d;
	d.Set(0.001f, 0.001f);
	aabb.lowerBound = p - d;
	aabb.upperBound = p + d;
	QueryCallback callback(p);
	world->QueryAABB(&callback, aabb);
	if(callback.m_fixture) {
		b2Body* body = callback.m_fixture->GetBody();
		b2MouseJointDef md;
		md.bodyA = groundBody;
		md.bodyB = body;
		md.target = p;
		md.maxForce = 1000.0f * body->GetMass();
		mouseJoint = (b2MouseJoint*)world->CreateJoint(&md);
		body->SetAwake(true);
    //[[NSNotificationCenter defaultCenter] postNotificationName:@"BodyTouchesBegan" object:nil];
		return;
	}
	return;
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
	UITouch *touch = [[event allTouches] anyObject];
	CGPoint touchZone = [touch locationInView:self];
  touchZone.x = touchZone.x;
  touchZone.y = 1024-touchZone.y;
	b2Vec2 p;
	p.Set(touchZone.x/PTM_RATIO, touchZone.y/PTM_RATIO);
	if (mouseJoint) {
		mouseJoint->SetTarget(p);
	}
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
	if(mouseJoint) {
    //[[NSNotificationCenter defaultCenter] postNotificationName:@"BodyTouchesEnded" object:nil];
		world->DestroyJoint(mouseJoint);
		mouseJoint = NULL;
	}
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
	if(mouseJoint) {
    //[[NSNotificationCenter defaultCenter] postNotificationName:@"BodyTouchesEnded" object:nil];
		world->DestroyJoint(mouseJoint);
		mouseJoint = NULL;
	}
}

@end
