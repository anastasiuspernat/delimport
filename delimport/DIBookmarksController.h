//
//  DIBookmarksController.h
//  delimport
//
//  Created by Ian Henderson on 30.04.05.
//  Copyright 2005 Ian Henderson. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#define DIMinutesBetweenChecks @"MinutesBetweenChecks"
#define DIDisplayErrorMessages @"DisplayErrorMessages"
#define DILoginAlertSuppressedKey @"Suppress Add To Login Items Alert"

#define DIDefaultsBookmarksKey @"DeliciousBookmarks"
#define DIDefaultsBookmarksDictKey @"BookmarksDictionary"
#define DIDefaultsLastUpdateKey @"DeliciousLastUpdate"
#define DIDefaultsServiceTypeKey @"serviceType"

@class DIFileController, DILoginController;

@interface DIBookmarksController : NSObject {
	DIFileController *fileController;
	DILoginController *loginController;
	
	NSString *username;
	NSString *password;

	NSMutableDictionary *bookmarks;
	NSDate *lastUpdate;
	NSDate *throttleTimepoint;
}

- (void) logIn;

- (NSDictionary *) loadBookmarksDictionary;
- (void) saveBookmarksDictionary: (NSDictionary *) list;

- (void) verifyMetadataCache;
- (void) updateList: (NSTimer *) timer;
- (NSDictionary *) postDictionaryForXML: (NSXMLElement *) postXML;
- (void) setBookmarks: (NSDictionary *) newMarks;

- (void) setupTimer: (NSTimer*) timer;
- (NSTimeInterval) currentUpdateInterval;

+ (NSString *) serverAddress;
+ (NSString *) serviceName;
+ (NSString *) versionString;
+ (NSString *) userAgentName;
+ (NSString *) DIApplicationSupportFolderPath;

@end
