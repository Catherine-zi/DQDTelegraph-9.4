#import "MTHttpRequestOperation.h"

#import "AFHTTPRequestOperation.h"

#import "MTDisposable.h"
#import "MTSignal.h"

@implementation MTHttpRequestOperation

+ (MTSignal *)dataForHttpUrl:(NSURL *)url {
    return [self dataForHttpUrl:url headers:nil];
}

+ (MTSignal *)dataForHttpUrl:(NSURL *)url headers:(NSDictionary *)headers {
    return [[MTSignal alloc] initWithGenerator:^id<MTDisposable>(MTSubscriber *subscriber) {
        NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
        [headers enumerateKeysAndObjectsUsingBlock:^(NSString *key, NSString *value, __unused BOOL *stop) {
            [request setValue:value forHTTPHeaderField:key];
        }];
        AFHTTPRequestOperation *operation = [[AFHTTPRequestOperation alloc] initWithRequest:request];
        
        [operation setSuccessCallbackQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)];
        [operation setFailureCallbackQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)];
        
        [operation setCompletionBlockWithSuccess:^(__unused AFHTTPRequestOperation *operation, __unused id responseObject)
        {
            [subscriber putNext:[operation responseData]];
            [subscriber putCompletion];
        } failure:^(__unused AFHTTPRequestOperation *operation, __unused NSError *error)
        {
            [subscriber putError:nil];
        }];
        
        [operation start];
        
        __weak AFHTTPRequestOperation *weakOperation = operation;
        
        return [[MTBlockDisposable alloc] initWithBlock:^
        {
            __strong AFHTTPRequestOperation *strongOperation = weakOperation;
            [strongOperation cancel];
        }];
    }];
}
@end
