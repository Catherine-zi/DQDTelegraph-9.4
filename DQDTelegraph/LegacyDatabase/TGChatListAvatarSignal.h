#import <Foundation/Foundation.h>

#import "SSignalKit.h"

#import "LegacyDatabase.h"

#import "TGPeerId.h"
#import "TGFileLocation.h"

@interface TGChatListAvatarSignal : NSObject

+ (SSignal *)chatListAvatarWithContext:(TGShareContext *)context location:(TGFileLocation *)location imageSize:(CGSize)imageSize;
+ (SSignal *)chatListAvatarWithContext:(TGShareContext *)context letters:(NSString *)letters peerId:(TGPeerId)peerId imageSize:(CGSize)imageSize;
+ (SSignal *)chatListAvatarForSavedMessagesWithContext:(TGShareContext *)context imageSize:(CGSize)imageSize;

@end
