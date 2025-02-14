/*
 This file is part of Ask4AppReviews.
 
 Copyright (c) 2012, Arash Payan
 All rights reserved.
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * Ask4AppReviews.h
 * Ask4AppReviews
 *
 * Created by Luke Durrant on 7/12.
 * Ask4AppReviews (forked from Appirater).
 */

#import <Foundation/Foundation.h>



extern NSString *const kAsk4AppReviewsFirstUseDate;
extern NSString *const kAsk4AppReviewsUseCount;
extern NSString *const kAsk4AppReviewsSignificantEventCount;
extern NSString *const kAsk4AppReviewsCurrentVersion;
extern NSString *const kAsk4AppReviewsRatedCurrentVersion;
extern NSString *const kAsk4AppReviewsDeclinedToRate;
extern NSString *const kAsk4AppReviewsReminderRequestDate;

/*
 Your localized app's name.
 */
#define Ask4AppReviews_LOCALIZED_APP_NAME    [[[NSBundle mainBundle] localizedInfoDictionary] objectForKey:(NSString *)kCFBundleNameKey]

/*
 Your app's name.
 */
#define Ask4AppReviews_APP_NAME				Ask4AppReviews_LOCALIZED_APP_NAME ? Ask4AppReviews_LOCALIZED_APP_NAME : [[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString*)kCFBundleNameKey]

/*
 This is the message your users will see once they've passed the day+launches
 threshold.
 */
#define Ask4AppReviews_LOCALIZED_MESSAGE     NSLocalizedString(@"If you enjoy using %@, would you mind taking a moment to rate it? It won't take more than a minute. Thanks for your support!", nil)
#define Ask4AppReviews_MESSAGE				[NSString stringWithFormat:Ask4AppReviews_LOCALIZED_MESSAGE, Ask4AppReviews_APP_NAME]

/*
 This is the title of the message alert that users will see.
 */
#define Ask4AppReviews_LOCALIZED_MESSAGE_TITLE   NSLocalizedString(@"Rate %@", nil)
#define Ask4AppReviews_MESSAGE_TITLE             [NSString stringWithFormat:Ask4AppReviews_LOCALIZED_MESSAGE_TITLE, Ask4AppReviews_APP_NAME]

/*
 The text of the button that rejects reviewing the app.
 */
#define Ask4AppReviews_CANCEL_BUTTON			NSLocalizedString(@"No, Thanks", nil)

/*
 Text of button that will send user to app review page.
 */
#define Ask4AppReviews_LOCALIZED_RATE_BUTTON NSLocalizedString(@"Rate %@", nil)
#define Ask4AppReviews_RATE_BUTTON			[NSString stringWithFormat:Ask4AppReviews_LOCALIZED_RATE_BUTTON, Ask4AppReviews_APP_NAME]



#define Ask4AppReviews_LOCALIZED_QUESTION_MESSAGE_TITLE   NSLocalizedString(@"%@ Feedback", nil)
#define Ask4AppReviews_QUESTION_MESSAGE_TITLE             [NSString stringWithFormat:Ask4AppReviews_LOCALIZED_QUESTION_MESSAGE_TITLE, Ask4AppReviews_APP_NAME]

#define Ask4AppReviews_LOCALIZED_QUESTION   NSLocalizedString(@"How do you feel about %@?", nil)
#define Ask4AppReviews_QUESTION             [NSString stringWithFormat:Ask4AppReviews_LOCALIZED_QUESTION, Ask4AppReviews_APP_NAME]


#define Ask4AppReviews_LOCALIZED_EMAIL_SUBJECT NSLocalizedString(@"Having issues with %@", nil)
#define Ask4AppReviews_EMAIL_SUBJECT			[NSString stringWithFormat:Ask4AppReviews_LOCALIZED_EMAIL_SUBJECT, Ask4AppReviews_APP_NAME]

#define Ask4AppReviews_EMAIL_BODY NSLocalizedString(@"Please describe your issue:\n", nil)

#define Ask4AppReviews_LOCALIZED_DEVELOPER_EMAIL_ALERT NSLocalizedString(@"Your device doesn't support sending email please email %@", nil)
#define Ask4AppReviews_DEVELOPER_EMAIL_ALERT			[NSString stringWithFormat:Ask4AppReviews_LOCALIZED_DEVELOPER_EMAIL_ALERT, [Ask4AppReviews developerEmail]]
 
/*
 Text for button to say the love it (no problems)
 */
#define Ask4AppReviews_NO NSLocalizedString(@"I love it!", nil)

/*
 Text for button to say somethings not right (email).
 */
#define Ask4AppReviews_YES NSLocalizedString(@"Something's not quite right", nil)

/*
 Text for button to remind the user to feedback.
 */
#define Ask4AppReviews_FEEDBACK NSLocalizedString(@"I have feedback", nil)


/*
 Text for button to remind the user to review later.
 */
#define Ask4AppReviews_RATE_LATER			NSLocalizedString(@"Remind me later", nil)

/*
 Users will need to have the same version of your app installed for this many
 days before they will be prompted to rate it.
 */
#define Ask4AppReviews_DAYS_UNTIL_PROMPT		30		// double

/*
 An example of a 'use' would be if the user launched the app. Bringing the app
 into the foreground (on devices that support it) would also be considered
 a 'use'. You tell Ask4AppReviews about these events using the two methods:
 [Ask4AppReviews appLaunched:]
 [Ask4AppReviews appEnteredForeground:]
 
 Users need to 'use' the same version of the app this many times before
 before they will be prompted to rate it.
 */
#define Ask4AppReviews_USES_UNTIL_PROMPT		20		// integer

/*
 A significant event can be anything you want to be in your app. In a
 telephone app, a significant event might be placing or receiving a call.
 In a game, it might be beating a level or a boss. This is just another
 layer of filtering that can be used to make sure that only the most
 loyal of your users are being prompted to rate you on the app store.
 If you leave this at a value of -1, then this won't be a criteria
 used for rating. To tell Ask4AppReviews that the user has performed
 a significant event, call the method:
 [Ask4AppReviews userDidSignificantEvent:];
 */
#define Ask4AppReviews_SIG_EVENTS_UNTIL_PROMPT	-1	// integer

/*
 Once the rating alert is presented to the user, they might select
 'Remind me later'. This value specifies how long (in days) Ask4AppReviews
 will wait before reminding them.
 */
#define Ask4AppReviews_TIME_BEFORE_REMINDING		1	// double

/*
 'YES' will show the Ask4AppReviews alert everytime. Useful for testing how your message
 looks and making sure the link to your app's review page works.
 */
#define Ask4AppReviews_DEBUG				YES

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>


@interface Ask4AppReviews : NSObject <UIAlertViewDelegate, MFMailComposeViewControllerDelegate> {

	UIAlertView		*questionAlert;
    UIAlertView		*ratingAlert;
    UIViewController *theViewController;
    
}
@property(nonatomic, retain) UIAlertView *questionAlert;
@property(nonatomic, retain) UIAlertView *ratingAlert;

@property(nonatomic, retain) UIViewController *theViewController;

/*
 DEPRECATED: While still functional, it's better to use
 appLaunched:(BOOL)canPromptForRating instead.
 
 Calls [Ask4AppReviews appLaunched:YES]. See appLaunched: for details of functionality.
 */
+ (void)appLaunched;

/*
 Tells Ask4AppReviews that the app has launched, and on devices that do NOT
 support multitasking, the 'uses' count will be incremented. You should
 call this method at the end of your application delegate's
 application:didFinishLaunchingWithOptions: method.
 
 If the app has been used enough to be rated (and enough significant events),
 you can suppress the rating alert
 by passing NO for canPromptForRating. The rating alert will simply be postponed
 until it is called again with YES for canPromptForRating. The rating alert
 can also be triggered by appEnteredForeground: and userDidSignificantEvent:
 (as long as you pass YES for canPromptForRating in those methods).
 */
+ (void)appLaunched:(BOOL)canPromptForRating;

+ (void)appLaunched:(BOOL)canPromptForRating viewController:(UINavigationController*)viewController;

/*
 Tells Ask4AppReviews that the app was brought to the foreground on multitasking
 devices. You should call this method from the application delegate's
 applicationWillEnterForeground: method.
 
 If the app has been used enough to be rated (and enough significant events),
 you can suppress the rating alert
 by passing NO for canPromptForRating. The rating alert will simply be postponed
 until it is called again with YES for canPromptForRating. The rating alert
 can also be triggered by appLaunched: and userDidSignificantEvent:
 (as long as you pass YES for canPromptForRating in those methods).
 */
+ (void)appEnteredForeground:(BOOL)canPromptForRating;



/*
 Tells Ask4AppReviews that the user performed a significant event. A significant
 event is whatever you want it to be. If you're app is used to make VoIP
 calls, then you might want to call this method whenever the user places
 a call. If it's a game, you might want to call this whenever the user
 beats a level boss.
 
 If the user has performed enough significant events and used the app enough,
 you can suppress the rating alert by passing NO for canPromptForRating. The
 rating alert will simply be postponed until it is called again with YES for
 canPromptForRating. The rating alert can also be triggered by appLaunched:
 and appEnteredForeground: (as long as you pass YES for canPromptForRating
 in those methods).
 */
+ (void)userDidSignificantEvent:(BOOL)canPromptForRating;

/*
 Tells Ask4AppReviews to open the App Store page where the user can specify a
 rating for the app. Also records the fact that this has happened, so the
 user won't be prompted again to rate the app.

 The only case where you should call this directly is if your app has an
 explicit "Rate this app" command somewhere.  In all other cases, don't worry
 about calling this -- instead, just call the other functions listed above,
 and let Ask4AppReviews handle the bookkeeping of deciding when to ask the user
 whether to rate the app.
 */
+ (void)rateApp;

@end
