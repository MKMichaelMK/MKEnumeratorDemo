//
//  ViewController.m
//  MKEnumeratorDemo
//
//  Created by Michael on 2017/7/29.
//  Copyright © 2017年 Michael. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    /*--------------------数组--------------------*/
    NSArray *anArray = @[@"1", @"2", @"a", @"b"];
    for (int i = 0; i < anArray.count; i++) {
        id object = anArray[i];
        NSLog(@"for 循环 array object = %@", object);
    }
    
    NSEnumerator *enumerator = [anArray objectEnumerator];
    //    NSEnumerator *enumerator = [anArray reverseObjectEnumerator];
    id object;
    while ((object = [enumerator nextObject]) != nil) {
        NSLog(@"NSEnumerator array object = %@", object);
    }
    
    for (id object in anArray) {
        NSLog(@"快速枚举 array object = %@", object);
    }
    
    [anArray enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSLog(@"块枚举 串行 array object = %@ thread = %@", obj, @([NSThread isMainThread]));
    }];
    
    [anArray enumerateObjectsWithOptions:NSEnumerationConcurrent usingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSLog(@"块枚举 并行 array object = %@ thread = %@", obj, @([NSThread isMainThread]));
    }];
    
    
    
    /*--------------------字典--------------------*/
    NSDictionary *aDictionary = @{@"a": @"1", @"b": @"2"};
    NSArray *keys = [aDictionary allKeys];
    for (int i = 0; i < keys.count; i++) {
        id key = keys[i];
        id value = aDictionary[key];
        NSLog(@"for 循环 dictionary value = %@", value);
    }
    
    enumerator = [aDictionary keyEnumerator];
    id key;
    while ((key = [enumerator nextObject]) != nil) {
        id value = aDictionary[key];
        NSLog(@"NSEnumerator dictionary value = %@", value);
    }
    
    for (id key in aDictionary) {
        id value = aDictionary[key];
        NSLog(@"快速枚举 dictionary value = %@", value);
    }
    
    [aDictionary enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, NSString * _Nonnull obj, BOOL * _Nonnull stop) {
        NSLog(@"块枚举 dictionary value = %@", obj);
    }];
    
    //    [aDictionary enumerateKeysAndObjectsWithOptions:NSEnumerationReverse usingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
    //
    //    }];
    
    
    /*--------------------集合--------------------*/
    NSSet *aSet = [NSSet setWithObjects:@"a", @"b", @"a", @"c", nil];
    NSArray *objects = [aSet allObjects];
    for (int i = 0; i < objects.count; i++) {
        id object = objects[i];
        NSLog(@"for 循环 set object = %@", object);
    }
    
    enumerator = [aSet objectEnumerator];
    while ((object = [enumerator nextObject]) != nil) {
        NSLog(@"NSEnumerator set object = %@", object);
    }
    
    for (id object in aSet) {
        NSLog(@"快速枚举 set object = %@", object);
    }
    
    [aSet enumerateObjectsUsingBlock:^(id  _Nonnull obj, BOOL * _Nonnull stop) {
        NSLog(@"块枚举 set object = %@", obj);
    }];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
