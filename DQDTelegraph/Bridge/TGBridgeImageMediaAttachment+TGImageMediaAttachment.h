#import "TGBridgeImageMediaAttachment.h"

#import "LegacyComponents.h"

@interface TGBridgeImageMediaAttachment (TGImageMediaAttachment)

+ (TGBridgeImageMediaAttachment *)attachmentWithTGImageMediaAttachment:(TGImageMediaAttachment *)attachment;

+ (TGImageMediaAttachment *)tgImageMediaAttachmentWithBridgeImageMediaAttachment:(TGBridgeImageMediaAttachment *)bridgeAttachment;

@end
