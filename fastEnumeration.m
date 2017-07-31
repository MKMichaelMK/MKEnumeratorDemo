#import <Foundation/NSArray.h>

int main(int argc, char * argv[]) {
    NSArray *array = @[ @1, @2, @3 ];
    for (NSNumber *number in array) {
        if ([number isEqualToNumber:@1]) {
            continue;
        }
        NSLog(@"%@", number);
        break;
    }
}
