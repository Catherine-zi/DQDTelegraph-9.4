#import "SSignalKit.h"

@interface TGTwoStepSetPaswordSignal : NSObject

+ (SSignal *)setPasswordWithCurrentSalt:(NSData *)currentSalt currentPassword:(NSString *)currentPassword nextSalt:(NSData *)nextSalt nextPassword:(NSString *)nextPassword nextHint:(NSString *)nextHint email:(NSString *)email;
+ (SSignal *)setPassword:(NSString *)password hint:(NSString *)hint email:(NSString *)email;
+ (SSignal *)setRecoveryEmail:(NSData *)currentSalt currentPassword:(NSString *)currentPassword recoveryEmail:(NSString *)recoveryEmail;

@end
