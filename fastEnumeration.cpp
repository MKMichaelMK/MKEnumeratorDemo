#ifndef __OBJC2__
#define __OBJC2__
#endif
struct objc_selector; struct objc_class;
struct __rw_objc_super {
    struct objc_object *object;
    struct objc_object *superClass;
    __rw_objc_super(struct objc_object *o, struct objc_object *s) : object(o), superClass(s) {}
};
#ifndef _REWRITER_typedef_Protocol
typedef struct objc_object Protocol;
#define _REWRITER_typedef_Protocol
#endif
#define __OBJC_RW_DLLIMPORT extern
__OBJC_RW_DLLIMPORT void objc_msgSend(void);
__OBJC_RW_DLLIMPORT void objc_msgSendSuper(void);
__OBJC_RW_DLLIMPORT void objc_msgSend_stret(void);
__OBJC_RW_DLLIMPORT void objc_msgSendSuper_stret(void);
__OBJC_RW_DLLIMPORT void objc_msgSend_fpret(void);
__OBJC_RW_DLLIMPORT struct objc_class *objc_getClass(const char *);
__OBJC_RW_DLLIMPORT struct objc_class *class_getSuperclass(struct objc_class *);
__OBJC_RW_DLLIMPORT struct objc_class *objc_getMetaClass(const char *);
__OBJC_RW_DLLIMPORT void objc_exception_throw( struct objc_object *);
__OBJC_RW_DLLIMPORT int objc_sync_enter( struct objc_object *);
__OBJC_RW_DLLIMPORT int objc_sync_exit( struct objc_object *);
__OBJC_RW_DLLIMPORT Protocol *objc_getProtocol(const char *);
#ifdef _WIN64
typedef unsigned long long  _WIN_NSUInteger;
#else
typedef unsigned int _WIN_NSUInteger;
#endif
#ifndef __FASTENUMERATIONSTATE
struct __objcFastEnumerationState {
    unsigned long state;
    void **itemsPtr;
    unsigned long *mutationsPtr;
    unsigned long extra[5];
};
__OBJC_RW_DLLIMPORT void objc_enumerationMutation(struct objc_object *);
#define __FASTENUMERATIONSTATE
#endif
#ifndef __NSCONSTANTSTRINGIMPL
struct __NSConstantStringImpl {
    int *isa;
    int flags;
    char *str;
#if _WIN64
    long long length;
#else
    long length;
#endif
};
#ifdef CF_EXPORT_CONSTANT_STRING
extern "C" __declspec(dllexport) int __CFConstantStringClassReference[];
#else
__OBJC_RW_DLLIMPORT int __CFConstantStringClassReference[];
#endif
#define __NSCONSTANTSTRINGIMPL
#endif
#ifndef BLOCK_IMPL
#define BLOCK_IMPL
struct __block_impl {
    void *isa;
    int Flags;
    int Reserved;
    void *FuncPtr;
};
// Runtime copy/destroy helper functions (from Block_private.h)
#ifdef __OBJC_EXPORT_BLOCKS
extern "C" __declspec(dllexport) void _Block_object_assign(void *, const void *, const int);
extern "C" __declspec(dllexport) void _Block_object_dispose(const void *, const int);
extern "C" __declspec(dllexport) void *_NSConcreteGlobalBlock[32];
extern "C" __declspec(dllexport) void *_NSConcreteStackBlock[32];
#else
__OBJC_RW_DLLIMPORT void _Block_object_assign(void *, const void *, const int);
__OBJC_RW_DLLIMPORT void _Block_object_dispose(const void *, const int);
__OBJC_RW_DLLIMPORT void *_NSConcreteGlobalBlock[32];
__OBJC_RW_DLLIMPORT void *_NSConcreteStackBlock[32];
#endif
#endif
#define __block
#define __weak

#include <stdarg.h>
struct __NSContainer_literal {
    void * *arr;
    __NSContainer_literal (unsigned int count, ...) {
        va_list marker;
        va_start(marker, count);
        arr = new void *[count];
        for (unsigned i = 0; i < count; i++)
            arr[i] = va_arg(marker, void *);
        va_end( marker );
    };
    ~__NSContainer_literal() {
        delete[] arr;
    }
};
extern "C" __declspec(dllimport) void * objc_autoreleasePoolPush(void);
extern "C" __declspec(dllimport) void objc_autoreleasePoolPop(void *);

struct __AtAutoreleasePool {
    __AtAutoreleasePool() {atautoreleasepoolobj = objc_autoreleasePoolPush();}
    ~__AtAutoreleasePool() {objc_autoreleasePoolPop(atautoreleasepoolobj);}
    void * atautoreleasepoolobj;
};

#define __OFFSETOFIVAR__(TYPE, MEMBER) ((long long) &((TYPE *)0)->MEMBER)
static __NSConstantStringImpl __NSConstantStringImpl__var_folders_xk_3y8751nj20gg8q246mkyz1x00000gn_T_fastEnumeration_e94cb1_mi_0 __attribute__ ((section ("__DATA, __cfstring"))) = {__CFConstantStringClassReference,0x000007c8,"%@",2};












typedef signed char __int8_t;



typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
typedef int __darwin_ct_rune_t;





typedef union {
    char __mbstate8[128];
    long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;


typedef long int __darwin_ptrdiff_t;







typedef long unsigned int __darwin_size_t;





typedef __builtin_va_list __darwin_va_list;





typedef int __darwin_wchar_t;




typedef __darwin_wchar_t __darwin_rune_t;


typedef int __darwin_wint_t;




typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;





typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;


typedef int64_t register_t;





typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;



typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;







typedef u_int64_t syscall_arg_t;
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;



typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];


struct __darwin_pthread_handler_rec {
    void (*__routine)(void *);
    void *__arg;
    struct __darwin_pthread_handler_rec *__next;
};

struct _opaque_pthread_attr_t {
    long __sig;
    char __opaque[56];
};

struct _opaque_pthread_cond_t {
    long __sig;
    char __opaque[40];
};

struct _opaque_pthread_condattr_t {
    long __sig;
    char __opaque[8];
};

struct _opaque_pthread_mutex_t {
    long __sig;
    char __opaque[56];
};

struct _opaque_pthread_mutexattr_t {
    long __sig;
    char __opaque[8];
};

struct _opaque_pthread_once_t {
    long __sig;
    char __opaque[8];
};

struct _opaque_pthread_rwlock_t {
    long __sig;
    char __opaque[192];
};

struct _opaque_pthread_rwlockattr_t {
    long __sig;
    char __opaque[16];
};

struct _opaque_pthread_t {
    long __sig;
    struct __darwin_pthread_handler_rec *__cleanup_stack;
    char __opaque[8176];
};

typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;

static inline
__uint16_t
_OSSwapInt16(
             __uint16_t _data
             )
{
    return ((__uint16_t)((_data << 8) | (_data >> 8)));
}

static inline
__uint32_t
_OSSwapInt32(
             __uint32_t _data
             )
{
    
    return __builtin_bswap32(_data);
    
    
    
    
}


static inline
__uint64_t
_OSSwapInt64(
             __uint64_t _data
             )
{
    return __builtin_bswap64(_data);
}


typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;

typedef unsigned long u_long;


typedef unsigned short ushort;
typedef unsigned int uint;


typedef u_int64_t u_quad_t;
typedef int64_t quad_t;
typedef quad_t * qaddr_t;

typedef char * caddr_t;
typedef int32_t daddr_t;


typedef __darwin_dev_t dev_t;

typedef u_int32_t fixpt_t;


typedef __darwin_blkcnt_t blkcnt_t;
typedef __darwin_blksize_t blksize_t;
typedef __darwin_gid_t gid_t;
typedef __uint32_t in_addr_t;
typedef __uint16_t in_port_t;
typedef __darwin_ino_t ino_t;


typedef __darwin_ino64_t ino64_t;


typedef __int32_t key_t;
typedef __darwin_mode_t mode_t;
typedef __uint16_t nlink_t;
typedef __darwin_id_t id_t;
typedef __darwin_pid_t pid_t;
typedef __darwin_off_t off_t;

typedef int32_t segsz_t;
typedef int32_t swblk_t;


typedef __darwin_uid_t uid_t;
static inline __int32_t major(__uint32_t _x)
{
    return (__int32_t)(((__uint32_t)_x >> 24) & 0xff);
}

static inline __int32_t minor(__uint32_t _x)
{
    return (__int32_t)((_x) & 0xffffff);
}

static inline dev_t makedev(__uint32_t _major, __uint32_t _minor)
{
    return (dev_t)(((_major) << 24) | (_minor));
}
typedef __darwin_clock_t clock_t;
typedef __darwin_size_t size_t;
typedef __darwin_ssize_t ssize_t;
typedef __darwin_time_t time_t;

typedef __darwin_useconds_t useconds_t;
typedef __darwin_suseconds_t suseconds_t;


typedef __darwin_size_t rsize_t;
typedef int errno_t;








extern "C" {
    typedef struct fd_set {
        __int32_t fds_bits[((((1024) % ((sizeof(__int32_t) * 8))) == 0) ? ((1024) / ((sizeof(__int32_t) * 8))) : (((1024) / ((sizeof(__int32_t) * 8))) + 1))];
    } fd_set;
}


static inline int
__darwin_fd_isset(int _n, const struct fd_set *_p)
{
    return (_p->fds_bits[(unsigned long)_n/(sizeof(__int32_t) * 8)] & ((__int32_t)(((unsigned long)1)<<((unsigned long)_n % (sizeof(__int32_t) * 8)))));
}




typedef __int32_t fd_mask;










typedef __darwin_pthread_attr_t pthread_attr_t;
typedef __darwin_pthread_cond_t pthread_cond_t;
typedef __darwin_pthread_condattr_t pthread_condattr_t;
typedef __darwin_pthread_mutex_t pthread_mutex_t;
typedef __darwin_pthread_mutexattr_t pthread_mutexattr_t;
typedef __darwin_pthread_once_t pthread_once_t;
typedef __darwin_pthread_rwlock_t pthread_rwlock_t;
typedef __darwin_pthread_rwlockattr_t pthread_rwlockattr_t;
typedef __darwin_pthread_t pthread_t;



typedef __darwin_pthread_key_t pthread_key_t;




typedef __darwin_fsblkcnt_t fsblkcnt_t;
typedef __darwin_fsfilcnt_t fsfilcnt_t;



typedef struct objc_class *Class;


struct objc_object {
    Class isa __attribute__((deprecated));
};


typedef struct objc_object *id;



typedef struct objc_selector *SEL;





typedef id (*IMP)(id, SEL, ...);
typedef signed char BOOL;
extern "C" __attribute__((visibility("default"))) const char *sel_getName(SEL sel)
__attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
extern "C" __attribute__((visibility("default"))) SEL sel_registerName(const char *str)
__attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
extern "C" __attribute__((visibility("default"))) const char *object_getClassName(id obj)
__attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
extern "C" __attribute__((visibility("default"))) void *object_getIndexedIvars(id obj)
__attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)))
;
extern "C" __attribute__((visibility("default"))) BOOL sel_isMapped(SEL sel)
__attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
extern "C" __attribute__((visibility("default"))) SEL sel_getUid(const char *str)
__attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));

typedef const void* objc_objectptr_t;




extern "C" __attribute__((visibility("default"))) id objc_retainedObject(objc_objectptr_t obj)
__attribute__((unavailable("use CFBridgingRelease() or a (__bridge_transfer id) cast instead")));
extern "C" __attribute__((visibility("default"))) id objc_unretainedObject(objc_objectptr_t obj)
__attribute__((unavailable("use a (__bridge id) cast instead")));
extern "C" __attribute__((visibility("default"))) objc_objectptr_t objc_unretainedPointer(id obj)
__attribute__((unavailable("use a __bridge cast instead")));
typedef long NSInteger;
typedef unsigned long NSUInteger;

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSMethodSignature
#define _REWRITER_typedef_NSMethodSignature
typedef struct objc_object NSMethodSignature;
typedef struct {} _objc_exc_NSMethodSignature;
#endif

#ifndef _REWRITER_typedef_NSInvocation
#define _REWRITER_typedef_NSInvocation
typedef struct objc_object NSInvocation;
typedef struct {} _objc_exc_NSInvocation;
#endif


// @protocol NSObject

// - (BOOL)isEqual:(id)object;
// @property (readonly) NSUInteger hash;

// @property (readonly) Class superclass;
// - (Class)class __attribute__((availability(swift, unavailable, message="use 'type(of: anObject)' instead")));
// - (instancetype)self;

// - (id)performSelector:(SEL)aSelector;
// - (id)performSelector:(SEL)aSelector withObject:(id)object;
// - (id)performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2;

// - (BOOL)isProxy;

// - (BOOL)isKindOfClass:(Class)aClass;
// - (BOOL)isMemberOfClass:(Class)aClass;
// - (BOOL)conformsToProtocol:(Protocol *)aProtocol;

// - (BOOL)respondsToSelector:(SEL)aSelector;

// - (instancetype)retain ;
// - (oneway void)release ;
// - (instancetype)autorelease ;
// - (NSUInteger)retainCount ;

// - (struct _NSZone *)zone ;

// @property (readonly, copy) NSString *description;
/* @optional */
// @property (readonly, copy) NSString *debugDescription;

/* @end */



__attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)))
__attribute__((objc_root_class))
extern "C" __attribute__((visibility("default")))

#ifndef _REWRITER_typedef_NSObject
#define _REWRITER_typedef_NSObject
typedef struct objc_object NSObject;
typedef struct {} _objc_exc_NSObject;
#endif

struct NSObject_IMPL {
    Class isa;
};


// + (void)load;

// + (void)initialize;
#if 0
- (instancetype)init

__attribute__((objc_designated_initializer))

;
#endif


// + (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
// + (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((availability(swift, unavailable, message="use object initializers instead")));
// + (instancetype)alloc __attribute__((availability(swift, unavailable, message="use object initializers instead")));
// - (void)dealloc __attribute__((availability(swift, unavailable, message="use 'deinit' to define a de-initializer")));

// - (void)finalize __attribute__((deprecated("Objective-C garbage collection is no longer supported")));

// - (id)copy;
// - (id)mutableCopy;

// + (id)copyWithZone:(struct _NSZone *)zone ;
// + (id)mutableCopyWithZone:(struct _NSZone *)zone ;

// + (BOOL)instancesRespondToSelector:(SEL)aSelector;
// + (BOOL)conformsToProtocol:(Protocol *)protocol;
// - (IMP)methodForSelector:(SEL)aSelector;
// + (IMP)instanceMethodForSelector:(SEL)aSelector;
// - (void)doesNotRecognizeSelector:(SEL)aSelector;

// - (id)forwardingTargetForSelector:(SEL)aSelector __attribute__((availability(macosx,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
// - (void)forwardInvocation:(NSInvocation *)anInvocation __attribute__((availability(swift, unavailable, message="")));
// - (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector __attribute__((availability(swift, unavailable, message="")));

// + (NSMethodSignature *)instanceMethodSignatureForSelector:(SEL)aSelector __attribute__((availability(swift, unavailable, message="")));

// - (BOOL)allowsWeakReference __attribute__((unavailable));
// - (BOOL)retainWeakReference __attribute__((unavailable));

// + (BOOL)isSubclassOfClass:(Class)aClass;

// + (BOOL)resolveClassMethod:(SEL)sel __attribute__((availability(macosx,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
// + (BOOL)resolveInstanceMethod:(SEL)sel __attribute__((availability(macosx,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));

// + (NSUInteger)hash;
// + (Class)superclass;
// + (Class)class __attribute__((availability(swift, unavailable, message="use 'aClass.self' instead")));
// + (NSString *)description;
// + (NSString *)debugDescription;

/* @end */

typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;



typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;
typedef long int intmax_t;
typedef long unsigned int uintmax_t;





extern "C" double NSFoundationVersionNumber;
// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_Protocol
#define _REWRITER_typedef_Protocol
typedef struct objc_object Protocol;
typedef struct {} _objc_exc_Protocol;
#endif


typedef NSString * NSExceptionName __attribute__((swift_wrapper(struct)));
typedef NSString * NSRunLoopMode __attribute__((swift_wrapper(struct)));

extern "C" NSString *NSStringFromSelector(SEL aSelector);
extern "C" SEL NSSelectorFromString(NSString *aSelectorName);

extern "C" NSString *NSStringFromClass(Class aClass);
extern "C" Class _Nullable NSClassFromString(NSString *aClassName);

extern "C" NSString *NSStringFromProtocol(Protocol *proto) __attribute__((availability(macosx,introduced=10_5)));
extern "C" Protocol * _Nullable NSProtocolFromString(NSString *namestr) __attribute__((availability(macosx,introduced=10_5)));

extern "C" const char *NSGetSizeAndAlignment(const char *typePtr, NSUInteger * _Nullable sizep, NSUInteger * _Nullable alignp);

extern "C" void NSLog(NSString *format, ...) __attribute__((format(__NSString__, 1, 2))) __attribute__((not_tail_called));
extern "C" void NSLogv(NSString *format, va_list args) __attribute__((format(__NSString__, 1, 0))) __attribute__((not_tail_called));

typedef NSInteger NSComparisonResult; enum {NSOrderedAscending = -1L, NSOrderedSame, NSOrderedDescending};


typedef NSComparisonResult (*NSComparator)(id obj1, id obj2);


typedef NSUInteger NSEnumerationOptions; enum {
    NSEnumerationConcurrent = (1UL << 0),
    NSEnumerationReverse = (1UL << 1),
};

typedef NSUInteger NSSortOptions; enum {
    NSSortConcurrent = (1UL << 0),
    NSSortStable = (1UL << 4),
};


typedef NSInteger NSQualityOfService; enum {
    
    NSQualityOfServiceUserInteractive = 0x21,
    
    
    NSQualityOfServiceUserInitiated = 0x19,
    
    
    NSQualityOfServiceUtility = 0x11,
    
    
    NSQualityOfServiceBackground = 0x09,
    
    
    NSQualityOfServiceDefault = -1
} __attribute__((availability(macosx,introduced=10_10)));

static const NSInteger NSNotFound = 9223372036854775807L;





extern "C" {
    
    
    
    
    
    extern "C" void *_Block_copy(const void *aBlock)
    __attribute__((availability(macosx,introduced=10.6)));
    
    
    extern "C" void _Block_release(const void *aBlock)
    __attribute__((availability(macosx,introduced=10.6)));
    
    
    
    extern "C" void _Block_object_assign(void *, const void *, const int)
    __attribute__((availability(macosx,introduced=10.6)));
    
    
    extern "C" void _Block_object_dispose(const void *, const int)
    __attribute__((availability(macosx,introduced=10.6)));
    
    
    extern "C" void * _NSConcreteGlobalBlock[32]
    __attribute__((availability(macosx,introduced=10.6)));
    extern "C" void * _NSConcreteStackBlock[32]
    __attribute__((availability(macosx,introduced=10.6)));
    
    
    
}




extern "C" {
    
    
#pragma pack(push, 2)
    typedef unsigned char UInt8;
    typedef signed char SInt8;
    typedef unsigned short UInt16;
    typedef signed short SInt16;
    
    
    typedef unsigned int UInt32;
    typedef signed int SInt32;
    struct wide {
        UInt32 lo;
        SInt32 hi;
    };
    typedef struct wide wide;
    struct UnsignedWide {
        UInt32 lo;
        UInt32 hi;
    };
    typedef struct UnsignedWide UnsignedWide;
    typedef signed long long SInt64;
    typedef unsigned long long UInt64;
    typedef SInt32 Fixed;
    typedef Fixed * FixedPtr;
    typedef SInt32 Fract;
    typedef Fract * FractPtr;
    typedef UInt32 UnsignedFixed;
    typedef UnsignedFixed * UnsignedFixedPtr;
    typedef short ShortFixed;
    typedef ShortFixed * ShortFixedPtr;
    typedef float Float32;
    typedef double Float64;
    struct Float80 {
        SInt16 exp;
        UInt16 man[4];
    };
    typedef struct Float80 Float80;
    
    struct Float96 {
        SInt16 exp[2];
        UInt16 man[4];
    };
    typedef struct Float96 Float96;
    struct Float32Point {
        Float32 x;
        Float32 y;
    };
    typedef struct Float32Point Float32Point;
    typedef char * Ptr;
    typedef Ptr * Handle;
    typedef long Size;
    typedef SInt16 OSErr;
    typedef SInt32 OSStatus;
    typedef void * LogicalAddress;
    typedef const void * ConstLogicalAddress;
    typedef void * PhysicalAddress;
    typedef UInt8 * BytePtr;
    typedef unsigned long ByteCount;
    typedef unsigned long ByteOffset;
    typedef SInt32 Duration;
    typedef UnsignedWide AbsoluteTime;
    typedef UInt32 OptionBits;
    typedef unsigned long ItemCount;
    typedef UInt32 PBVersion;
    typedef SInt16 ScriptCode;
    typedef SInt16 LangCode;
    typedef SInt16 RegionCode;
    typedef UInt32 FourCharCode;
    typedef FourCharCode OSType;
    typedef FourCharCode ResType;
    typedef OSType * OSTypePtr;
    typedef ResType * ResTypePtr;
    typedef unsigned char Boolean;
    typedef long ( * ProcPtr)();
    typedef void ( * Register68kProcPtr)();
    
    
    
    
    typedef ProcPtr UniversalProcPtr;
    
    
    typedef ProcPtr * ProcHandle;
    typedef UniversalProcPtr * UniversalProcHandle;
    typedef void * PRefCon;
    
    typedef void * URefCon;
    typedef void * SRefCon;
    enum {
        noErr = 0
    };
    
    enum {
        kNilOptions = 0
    };
    
    
    enum {
        kVariableLengthArray
        
        
        __attribute__((deprecated))
        
        
        = 1
    };
    
    enum {
        kUnknownType = 0x3F3F3F3F
    };
    typedef UInt32 UnicodeScalarValue;
    typedef UInt32 UTF32Char;
    typedef UInt16 UniChar;
    typedef UInt16 UTF16Char;
    typedef UInt8 UTF8Char;
    typedef UniChar * UniCharPtr;
    typedef unsigned long UniCharCount;
    typedef UniCharCount * UniCharCountPtr;
    typedef unsigned char Str255[256];
    typedef unsigned char Str63[64];
    typedef unsigned char Str32[33];
    typedef unsigned char Str31[32];
    typedef unsigned char Str27[28];
    typedef unsigned char Str15[16];
    typedef unsigned char Str32Field[34];
    typedef Str63 StrFileName;
    typedef unsigned char * StringPtr;
    typedef StringPtr * StringHandle;
    typedef const unsigned char * ConstStringPtr;
    typedef const unsigned char * ConstStr255Param;
    typedef const unsigned char * ConstStr63Param;
    typedef const unsigned char * ConstStr32Param;
    typedef const unsigned char * ConstStr31Param;
    typedef const unsigned char * ConstStr27Param;
    typedef const unsigned char * ConstStr15Param;
    typedef ConstStr63Param ConstStrFileNameParam;
    
    inline unsigned char StrLength(ConstStr255Param string) { return (*string); }
    struct ProcessSerialNumber {
        UInt32 highLongOfPSN;
        UInt32 lowLongOfPSN;
    };
    typedef struct ProcessSerialNumber ProcessSerialNumber;
    typedef ProcessSerialNumber * ProcessSerialNumberPtr;
    struct Point {
        short v;
        short h;
    };
    typedef struct Point Point;
    typedef Point * PointPtr;
    struct Rect {
        short top;
        short left;
        short bottom;
        short right;
    };
    typedef struct Rect Rect;
    typedef Rect * RectPtr;
    struct FixedPoint {
        Fixed x;
        Fixed y;
    };
    typedef struct FixedPoint FixedPoint;
    struct FixedRect {
        Fixed left;
        Fixed top;
        Fixed right;
        Fixed bottom;
    };
    typedef struct FixedRect FixedRect;
    
    typedef short CharParameter;
    enum {
        normal = 0,
        bold = 1,
        italic = 2,
        underline = 4,
        outline = 8,
        shadow = 0x10,
        condense = 0x20,
        extend = 0x40
    };
    
    typedef unsigned char Style;
    typedef short StyleParameter;
    typedef Style StyleField;
    typedef SInt32 TimeValue;
    typedef SInt32 TimeScale;
    typedef wide CompTimeValue;
    typedef SInt64 TimeValue64;
    typedef struct TimeBaseRecord* TimeBase;
    struct TimeRecord {
        CompTimeValue value;
        TimeScale scale;
        TimeBase base;
    };
    typedef struct TimeRecord TimeRecord;
    struct NumVersion {
        
        UInt8 nonRelRev;
        UInt8 stage;
        UInt8 minorAndBugRev;
        UInt8 majorRev;
    };
    typedef struct NumVersion NumVersion;
    
    
    enum {
        
        developStage = 0x20,
        alphaStage = 0x40,
        betaStage = 0x60,
        finalStage = 0x80
    };
    
    union NumVersionVariant {
        
        NumVersion parts;
        UInt32 whole;
    };
    typedef union NumVersionVariant NumVersionVariant;
    typedef NumVersionVariant * NumVersionVariantPtr;
    typedef NumVersionVariantPtr * NumVersionVariantHandle;
    struct VersRec {
        
        NumVersion numericVersion;
        short countryCode;
        Str255 shortVersion;
        Str255 reserved;
    };
    typedef struct VersRec VersRec;
    typedef VersRec * VersRecPtr;
    typedef VersRecPtr * VersRecHndl;
    
    
    
    
    
    typedef UInt8 Byte;
    typedef SInt8 SignedByte;
    typedef wide * WidePtr;
    typedef UnsignedWide * UnsignedWidePtr;
    typedef Float80 extended80;
    typedef Float96 extended96;
    typedef SInt8 VHSelect;
    extern void
    Debugger(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
    extern void
    DebugStr(ConstStr255Param debuggerMsg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
    extern void
    SysBreak(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
    extern void
    SysBreakStr(ConstStr255Param debuggerMsg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
    extern void
    SysBreakFunc(ConstStr255Param debuggerMsg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
#pragma pack(pop)
    
    
}
extern "C" {
    // @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
    typedef struct objc_object NSArray;
    typedef struct {} _objc_exc_NSArray;
#endif
    
    // @class NSAttributedString;
#ifndef _REWRITER_typedef_NSAttributedString
#define _REWRITER_typedef_NSAttributedString
    typedef struct objc_object NSAttributedString;
    typedef struct {} _objc_exc_NSAttributedString;
#endif
    
    // @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
    typedef struct objc_object NSString;
    typedef struct {} _objc_exc_NSString;
#endif
    
    // @class NSNull;
#ifndef _REWRITER_typedef_NSNull
#define _REWRITER_typedef_NSNull
    typedef struct objc_object NSNull;
    typedef struct {} _objc_exc_NSNull;
#endif
    
    // @class NSCharacterSet;
#ifndef _REWRITER_typedef_NSCharacterSet
#define _REWRITER_typedef_NSCharacterSet
    typedef struct objc_object NSCharacterSet;
    typedef struct {} _objc_exc_NSCharacterSet;
#endif
    
    // @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
    typedef struct objc_object NSData;
    typedef struct {} _objc_exc_NSData;
#endif
    
    // @class NSDate;
#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
    typedef struct objc_object NSDate;
    typedef struct {} _objc_exc_NSDate;
#endif
    
    // @class NSTimeZone;
#ifndef _REWRITER_typedef_NSTimeZone
#define _REWRITER_typedef_NSTimeZone
    typedef struct objc_object NSTimeZone;
    typedef struct {} _objc_exc_NSTimeZone;
#endif
    
    // @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
    typedef struct objc_object NSDictionary;
    typedef struct {} _objc_exc_NSDictionary;
#endif
    
    // @class NSError;
#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
    typedef struct objc_object NSError;
    typedef struct {} _objc_exc_NSError;
#endif
    
    // @class NSLocale;
#ifndef _REWRITER_typedef_NSLocale
#define _REWRITER_typedef_NSLocale
    typedef struct objc_object NSLocale;
    typedef struct {} _objc_exc_NSLocale;
#endif
    
    // @class NSNumber;
#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
    typedef struct objc_object NSNumber;
    typedef struct {} _objc_exc_NSNumber;
#endif
    
    // @class NSSet;
#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
    typedef struct objc_object NSSet;
    typedef struct {} _objc_exc_NSSet;
#endif
    
    // @class NSURL;
#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
    typedef struct objc_object NSURL;
    typedef struct {} _objc_exc_NSURL;
#endif
    
    extern double kCFCoreFoundationVersionNumber;
    typedef unsigned long CFTypeID;
    typedef unsigned long CFOptionFlags;
    typedef unsigned long CFHashCode;
    typedef signed long CFIndex;
    
    
    
    typedef const __attribute__((objc_bridge(id))) void * CFTypeRef;
    
    typedef const struct __attribute__((objc_bridge(NSString))) __CFString * CFStringRef;
    typedef struct __attribute__((objc_bridge_mutable(NSMutableString))) __CFString * CFMutableStringRef;
    
    
    
    
    
    
    typedef __attribute__((objc_bridge(id))) CFTypeRef CFPropertyListRef;
    
    
    typedef CFIndex CFComparisonResult; enum {
        kCFCompareLessThan = -1L,
        kCFCompareEqualTo = 0,
        kCFCompareGreaterThan = 1
    };
    
    
    typedef CFComparisonResult (*CFComparatorFunction)(const void *val1, const void *val2, void *context);
    
    
    static const CFIndex kCFNotFound = -1;
    
    
    
    typedef struct {
        CFIndex location;
        CFIndex length;
    } CFRange;
    
    
    static __inline__ __attribute__((always_inline)) CFRange CFRangeMake(CFIndex loc, CFIndex len) {
        CFRange range;
        range.location = loc;
        range.length = len;
        return range;
    }
    
    
    
    
    
    extern
    CFRange __CFRangeMake(CFIndex loc, CFIndex len);
    
    
    
    
    typedef const struct __attribute__((objc_bridge(NSNull))) __CFNull * CFNullRef;
    
    extern
    CFTypeID CFNullGetTypeID(void);
    
    extern
    const CFNullRef kCFNull;
    typedef const struct __attribute__((objc_bridge(id))) __CFAllocator * CFAllocatorRef;
    
    
    extern
    const CFAllocatorRef kCFAllocatorDefault;
    
    
    extern
    const CFAllocatorRef kCFAllocatorSystemDefault;
    
    
    
    
    
    
    
    extern
    const CFAllocatorRef kCFAllocatorMalloc;
    
    
    
    
    
    extern
    const CFAllocatorRef kCFAllocatorMallocZone;
    
    
    
    
    
    extern
    const CFAllocatorRef kCFAllocatorNull;
    
    
    
    
    
    extern
    const CFAllocatorRef kCFAllocatorUseContext;
    
    typedef const void * (*CFAllocatorRetainCallBack)(const void *info);
    typedef void (*CFAllocatorReleaseCallBack)(const void *info);
    typedef CFStringRef (*CFAllocatorCopyDescriptionCallBack)(const void *info);
    typedef void * (*CFAllocatorAllocateCallBack)(CFIndex allocSize, CFOptionFlags hint, void *info);
    typedef void * (*CFAllocatorReallocateCallBack)(void *ptr, CFIndex newsize, CFOptionFlags hint, void *info);
    typedef void (*CFAllocatorDeallocateCallBack)(void *ptr, void *info);
    typedef CFIndex (*CFAllocatorPreferredSizeCallBack)(CFIndex size, CFOptionFlags hint, void *info);
    typedef struct {
        CFIndex version;
        void * info;
        CFAllocatorRetainCallBack retain;
        CFAllocatorReleaseCallBack release;
        CFAllocatorCopyDescriptionCallBack copyDescription;
        CFAllocatorAllocateCallBack allocate;
        CFAllocatorReallocateCallBack reallocate;
        CFAllocatorDeallocateCallBack deallocate;
        CFAllocatorPreferredSizeCallBack preferredSize;
    } CFAllocatorContext;
    
    extern
    CFTypeID CFAllocatorGetTypeID(void);
    extern
    void CFAllocatorSetDefault(CFAllocatorRef allocator);
    
    extern
    CFAllocatorRef CFAllocatorGetDefault(void);
    
    extern
    CFAllocatorRef CFAllocatorCreate(CFAllocatorRef allocator, CFAllocatorContext *context);
    
    extern
    void *CFAllocatorAllocate(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);
    
    extern
    void *CFAllocatorReallocate(CFAllocatorRef allocator, void *ptr, CFIndex newsize, CFOptionFlags hint);
    
    extern
    void CFAllocatorDeallocate(CFAllocatorRef allocator, void *ptr);
    
    extern
    CFIndex CFAllocatorGetPreferredSizeForSize(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);
    
    extern
    void CFAllocatorGetContext(CFAllocatorRef allocator, CFAllocatorContext *context);
    
    
    
    
    
    
    extern
    CFTypeID CFGetTypeID(CFTypeRef cf);
    
    extern
    CFStringRef CFCopyTypeIDDescription(CFTypeID type_id);
    
    extern
    CFTypeRef CFRetain(CFTypeRef cf);
    
    extern
    void CFRelease(CFTypeRef cf);
    
    
    
    extern
    CFTypeRef CFAutorelease(CFTypeRef __attribute__((cf_consumed)) arg) __attribute__((availability(macosx,introduced=10_9)));
    
    extern
    CFIndex CFGetRetainCount(CFTypeRef cf);
    
    
    extern
    Boolean CFEqual(CFTypeRef cf1, CFTypeRef cf2);
    
    extern
    CFHashCode CFHash(CFTypeRef cf);
    
    extern
    CFStringRef CFCopyDescription(CFTypeRef cf);
    
    extern
    CFAllocatorRef CFGetAllocator(CFTypeRef cf);
    
    
    
    
    extern
    CFTypeRef CFMakeCollectable(CFTypeRef cf) ;
    
}

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif




typedef struct _NSZone NSZone;

extern "C" NSZone *NSDefaultMallocZone(void) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" NSZone *NSCreateZone(NSUInteger startSize, NSUInteger granularity, BOOL canFree) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" void NSRecycleZone(NSZone *zone)__attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));

extern "C" void NSSetZoneName(NSZone * _Nullable zone, NSString *name)__attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" NSString *NSZoneName(NSZone * _Nullable zone) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" NSZone * _Nullable NSZoneFromPointer(void *ptr) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));

extern "C" void *NSZoneMalloc(NSZone * _Nullable zone, NSUInteger size) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" void *NSZoneCalloc(NSZone * _Nullable zone, NSUInteger numElems, NSUInteger byteSize) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" void *NSZoneRealloc(NSZone * _Nullable zone, void * _Nullable ptr, NSUInteger size) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" void NSZoneFree(NSZone * _Nullable zone, void *ptr) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));





enum {
    NSScannedOption = (1UL << 0),
    NSCollectorDisabledOption = (1UL << 1),
};

extern "C" void *NSAllocateCollectable(NSUInteger size, NSUInteger options) __attribute__((availability(swift, unavailable, message="Garbage Collection is not supported")));
extern "C" void *NSReallocateCollectable(void * _Nullable ptr, NSUInteger size, NSUInteger options) __attribute__((availability(swift, unavailable, message="Garbage Collection is not supported")));
static __inline__ __attribute__((always_inline)) __attribute__((ns_returns_retained)) id _Nullable NSMakeCollectable(CFTypeRef _Nullable __attribute__((cf_consumed)) cf) __attribute__((availability(swift, unavailable, message="Garbage Collection is not supported")));
static __inline__ __attribute__((always_inline)) __attribute__((ns_returns_retained)) id _Nullable NSMakeCollectable(CFTypeRef _Nullable __attribute__((cf_consumed)) cf) {
    
    
    
    return (id)cf;
    
}

extern "C" NSUInteger NSPageSize(void);
extern "C" NSUInteger NSLogPageSize(void);
extern "C" NSUInteger NSRoundUpToMultipleOfPageSize(NSUInteger bytes);
extern "C" NSUInteger NSRoundDownToMultipleOfPageSize(NSUInteger bytes);
extern "C" void *NSAllocateMemoryPages(NSUInteger bytes);
extern "C" void NSDeallocateMemoryPages(void *ptr, NSUInteger bytes);
extern "C" void NSCopyMemoryPages(const void *source, void *dest, NSUInteger bytes);
extern "C" NSUInteger NSRealMemoryAvailable(void) __attribute__((availability(macosx,introduced=10_0,deprecated=10_8,message="" )));

// @class NSInvocation;
#ifndef _REWRITER_typedef_NSInvocation
#define _REWRITER_typedef_NSInvocation
typedef struct objc_object NSInvocation;
typedef struct {} _objc_exc_NSInvocation;
#endif

#ifndef _REWRITER_typedef_NSMethodSignature
#define _REWRITER_typedef_NSMethodSignature
typedef struct objc_object NSMethodSignature;
typedef struct {} _objc_exc_NSMethodSignature;
#endif

#ifndef _REWRITER_typedef_NSCoder
#define _REWRITER_typedef_NSCoder
typedef struct objc_object NSCoder;
typedef struct {} _objc_exc_NSCoder;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSEnumerator
#define _REWRITER_typedef_NSEnumerator
typedef struct objc_object NSEnumerator;
typedef struct {} _objc_exc_NSEnumerator;
#endif

// @class Protocol;
#ifndef _REWRITER_typedef_Protocol
#define _REWRITER_typedef_Protocol
typedef struct objc_object Protocol;
typedef struct {} _objc_exc_Protocol;
#endif






// @protocol NSCopying

// - (id)copyWithZone:(nullable NSZone *)zone;

/* @end */


// @protocol NSMutableCopying

// - (id)mutableCopyWithZone:(nullable NSZone *)zone;

/* @end */


// @protocol NSCoding

// - (void)encodeWithCoder:(NSCoder *)aCoder;
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder;

/* @end */





// @protocol NSSecureCoding <NSCoding>
/* @required */



@property (class, readonly) BOOL supportsSecureCoding;



/* @end */




// @interface NSObject (NSCoderMethods)

// + (NSInteger)version;
// + (void)setVersion:(NSInteger)aVersion;
// @property (readonly) Class classForCoder;
// - (nullable id)replacementObjectForCoder:(NSCoder *)aCoder;
// - (nullable id)awakeAfterUsingCoder:(NSCoder *)aDecoder __attribute__((ns_consumes_self)) __attribute__((ns_returns_retained));

/* @end */



// @interface NSObject (NSDeprecatedMethods)

#if 0
+ (void)poseAsClass:(Class)aClass __attribute__((availability(macosx,introduced=10_0,deprecated=10_5,message="" )))

__attribute__((unavailable))

;
#endif


/* @end */






// @protocol NSDiscardableContent
/* @required */
// - (BOOL)beginContentAccess;
// - (void)endContentAccess;
// - (void)discardContentIfPossible;
// - (BOOL)isContentDiscarded;
/* @end */


// @interface NSObject (NSDiscardableContentProxy)
// @property (readonly, retain) id autoContentAccessingProxy __attribute__((availability(macosx,introduced=10_6)));
/* @end */




extern "C" id NSAllocateObject(Class aClass, NSUInteger extraBytes, NSZone * _Nullable zone) ;

extern "C" void NSDeallocateObject(id object) ;

extern "C" id NSCopyObject(id object, NSUInteger extraBytes, NSZone * _Nullable zone) __attribute__((availability(macosx,introduced=10_0,deprecated=10_8,message="" )));

extern "C" BOOL NSShouldRetainWithZone(id anObject, NSZone * _Nullable requestedZone) ;

extern "C" void NSIncrementExtraRefCount(id object) ;

extern "C" BOOL NSDecrementExtraRefCountWasZero(id object) ;

extern "C" NSUInteger NSExtraRefCount(id object) ;
static __inline__ __attribute__((always_inline)) __attribute__((cf_returns_retained)) CFTypeRef _Nullable CFBridgingRetain(id _Nullable X) {
    return X ? CFRetain((CFTypeRef)X) : __null;
}


static __inline__ __attribute__((always_inline)) id _Nullable CFBridgingRelease(CFTypeRef __attribute__((cf_consumed)) _Nullable X) {
    return ((id (*)(id, SEL))(void *)objc_msgSend)((id)CFMakeCollectable(X), sel_registerName("autorelease"));
}






// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

typedef struct {
    unsigned long state;
    id __attribute__((objc_ownership(none))) _Nullable * _Nullable itemsPtr;
    unsigned long * _Nullable mutationsPtr;
    unsigned long extra[5];
} NSFastEnumerationState;

// @protocol NSFastEnumeration

// - (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id __attribute__((objc_ownership(none))) _Nullable [_Nonnull])buffer count:(NSUInteger)len;

/* @end */



#ifndef _REWRITER_typedef_NSEnumerator
#define _REWRITER_typedef_NSEnumerator
typedef struct objc_object NSEnumerator;
typedef struct {} _objc_exc_NSEnumerator;
#endif

struct NSEnumerator_IMPL {
    struct NSObject_IMPL NSObject_IVARS;
};


// - (nullable ObjectType)nextObject;

/* @end */


// @interface NSEnumerator<ObjectType> (NSExtendedEnumerator)

// @property (readonly, copy) NSArray<ObjectType> *allObjects;

/* @end */











// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif





#ifndef _REWRITER_typedef_NSValue
#define _REWRITER_typedef_NSValue
typedef struct objc_object NSValue;
typedef struct {} _objc_exc_NSValue;
#endif

struct NSValue_IMPL {
    struct NSObject_IMPL NSObject_IVARS;
};


// - (void)getValue:(void *)value;
// @property (readonly) const char *objCType __attribute__((objc_returns_inner_pointer));

// - (instancetype)initWithBytes:(const void *)value objCType:(const char *)type __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSValue (NSValueCreation)

// + (NSValue *)valueWithBytes:(const void *)value objCType:(const char *)type;
// + (NSValue *)value:(const void *)value withObjCType:(const char *)type;

/* @end */


// @interface NSValue (NSValueExtensionMethods)

// + (NSValue *)valueWithNonretainedObject:(nullable id)anObject;
// @property (nullable, readonly) id nonretainedObjectValue;

// + (NSValue *)valueWithPointer:(nullable const void *)pointer;
// @property (nullable, readonly) void *pointerValue;

// - (BOOL)isEqualToValue:(NSValue *)value;

/* @end */



#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif

struct NSNumber_IMPL {
    struct NSValue_IMPL NSValue_IVARS;
};


// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithChar:(char)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedChar:(unsigned char)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithShort:(short)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedShort:(unsigned short)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithInt:(int)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedInt:(unsigned int)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithLong:(long)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedLong:(unsigned long)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithLongLong:(long long)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedLongLong:(unsigned long long)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithFloat:(float)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithDouble:(double)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithBool:(BOOL)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithInteger:(NSInteger)value __attribute__((availability(macosx,introduced=10_5))) __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedInteger:(NSUInteger)value __attribute__((availability(macosx,introduced=10_5))) __attribute__((objc_designated_initializer));

// @property (readonly) char charValue;
// @property (readonly) unsigned char unsignedCharValue;
// @property (readonly) short shortValue;
// @property (readonly) unsigned short unsignedShortValue;
// @property (readonly) int intValue;
// @property (readonly) unsigned int unsignedIntValue;
// @property (readonly) long longValue;
// @property (readonly) unsigned long unsignedLongValue;
// @property (readonly) long long longLongValue;
// @property (readonly) unsigned long long unsignedLongLongValue;
// @property (readonly) float floatValue;
// @property (readonly) double doubleValue;
// @property (readonly) BOOL boolValue;
// @property (readonly) NSInteger integerValue __attribute__((availability(macosx,introduced=10_5)));
// @property (readonly) NSUInteger unsignedIntegerValue __attribute__((availability(macosx,introduced=10_5)));

// @property (readonly, copy) NSString *stringValue;

// - (NSComparisonResult)compare:(NSNumber *)otherNumber;

// - (BOOL)isEqualToNumber:(NSNumber *)number;

// - (NSString *)descriptionWithLocale:(nullable id)locale;

/* @end */


// @interface NSNumber (NSNumberCreation)

// + (NSNumber *)numberWithChar:(char)value;
// + (NSNumber *)numberWithUnsignedChar:(unsigned char)value;
// + (NSNumber *)numberWithShort:(short)value;
// + (NSNumber *)numberWithUnsignedShort:(unsigned short)value;
// + (NSNumber *)numberWithInt:(int)value;
// + (NSNumber *)numberWithUnsignedInt:(unsigned int)value;
// + (NSNumber *)numberWithLong:(long)value;
// + (NSNumber *)numberWithUnsignedLong:(unsigned long)value;
// + (NSNumber *)numberWithLongLong:(long long)value;
// + (NSNumber *)numberWithUnsignedLongLong:(unsigned long long)value;
// + (NSNumber *)numberWithFloat:(float)value;
// + (NSNumber *)numberWithDouble:(double)value;
// + (NSNumber *)numberWithBool:(BOOL)value;
// + (NSNumber *)numberWithInteger:(NSInteger)value __attribute__((availability(macosx,introduced=10_5)));
// + (NSNumber *)numberWithUnsignedInteger:(NSUInteger)value __attribute__((availability(macosx,introduced=10_5)));

/* @end */



// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif




typedef struct _NSRange {
    NSUInteger location;
    NSUInteger length;
} NSRange;

typedef NSRange *NSRangePointer;

static __inline__ __attribute__((always_inline)) NSRange NSMakeRange(NSUInteger loc, NSUInteger len) {
    NSRange r;
    r.location = loc;
    r.length = len;
    return r;
}

static __inline__ __attribute__((always_inline)) NSUInteger NSMaxRange(NSRange range) {
    return (range.location + range.length);
}

static __inline__ __attribute__((always_inline)) BOOL NSLocationInRange(NSUInteger loc, NSRange range) {
    return (!(loc < range.location) && (loc - range.location) < range.length) ? ((bool)1) : ((bool)0);
}

static __inline__ __attribute__((always_inline)) BOOL NSEqualRanges(NSRange range1, NSRange range2) {
    return (range1.location == range2.location && range1.length == range2.length);
}

extern "C" NSRange NSUnionRange(NSRange range1, NSRange range2);
extern "C" NSRange NSIntersectionRange(NSRange range1, NSRange range2);
extern "C" NSString *NSStringFromRange(NSRange range);
extern "C" NSRange NSRangeFromString(NSString *aString);

// @interface NSValue (NSValueRangeExtensions)

// + (NSValue *)valueWithRange:(NSRange)range;
// @property (readonly) NSRange rangeValue;

/* @end */



// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSIndexSet
#define _REWRITER_typedef_NSIndexSet
typedef struct objc_object NSIndexSet;
typedef struct {} _objc_exc_NSIndexSet;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif







#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

struct NSArray_IMPL {
    struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly) NSUInteger count;
// - (ObjectType)objectAtIndex:(NSUInteger)index;
// - (instancetype)init __attribute__((objc_designated_initializer));
// - (instancetype)initWithObjects:(const ObjectType _Nonnull [_Nullable])objects count:(NSUInteger)cnt __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSArray<ObjectType> (NSExtendedArray)

// - (NSArray<ObjectType> *)arrayByAddingObject:(ObjectType)anObject;
// - (NSArray<ObjectType> *)arrayByAddingObjectsFromArray:(NSArray<ObjectType> *)otherArray;
// - (NSString *)componentsJoinedByString:(NSString *)separator;
// - (BOOL)containsObject:(ObjectType)anObject;
// @property (readonly, copy) NSString *description;
// - (NSString *)descriptionWithLocale:(nullable id)locale;
// - (NSString *)descriptionWithLocale:(nullable id)locale indent:(NSUInteger)level;
// - (nullable ObjectType)firstObjectCommonWithArray:(NSArray<ObjectType> *)otherArray;
// - (void)getObjects:(ObjectType __attribute__((objc_ownership(none))) [])objects range:(NSRange)range __attribute__((availability(swift, unavailable, message="Use 'subarrayWithRange()' instead")));
// - (NSUInteger)indexOfObject:(ObjectType)anObject;
// - (NSUInteger)indexOfObject:(ObjectType)anObject inRange:(NSRange)range;
// - (NSUInteger)indexOfObjectIdenticalTo:(ObjectType)anObject;
// - (NSUInteger)indexOfObjectIdenticalTo:(ObjectType)anObject inRange:(NSRange)range;
// - (BOOL)isEqualToArray:(NSArray<ObjectType> *)otherArray;
// @property (nullable, nonatomic, readonly) ObjectType firstObject __attribute__((availability(macosx,introduced=10_6)));
// @property (nullable, nonatomic, readonly) ObjectType lastObject;
// - (NSEnumerator<ObjectType> *)objectEnumerator;
// - (NSEnumerator<ObjectType> *)reverseObjectEnumerator;
// @property (readonly, copy) NSData *sortedArrayHint;
// - (NSArray<ObjectType> *)sortedArrayUsingFunction:(NSInteger (__attribute__((noescape)) *)(ObjectType, ObjectType, void * _Nullable))comparator context:(nullable void *)context;
// - (NSArray<ObjectType> *)sortedArrayUsingFunction:(NSInteger (__attribute__((noescape)) *)(ObjectType, ObjectType, void * _Nullable))comparator context:(nullable void *)context hint:(nullable NSData *)hint;
// - (NSArray<ObjectType> *)sortedArrayUsingSelector:(SEL)comparator;
// - (NSArray<ObjectType> *)subarrayWithRange:(NSRange)range;
// - (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;
// - (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically;

// - (void)makeObjectsPerformSelector:(SEL)aSelector __attribute__((availability(swift, unavailable, message="Use enumerateObjectsUsingBlock: or a for loop instead")));
// - (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(nullable id)argument __attribute__((availability(swift, unavailable, message="Use enumerateObjectsUsingBlock: or a for loop instead")));

// - (NSArray<ObjectType> *)objectsAtIndexes:(NSIndexSet *)indexes;

// - (ObjectType)objectAtIndexedSubscript:(NSUInteger)idx __attribute__((availability(macosx,introduced=10_8)));

// - (void)enumerateObjectsUsingBlock:(void (__attribute__((noescape)) ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block __attribute__((availability(macosx,introduced=10_6)));
// - (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (__attribute__((noescape)) ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block __attribute__((availability(macosx,introduced=10_6)));
// - (void)enumerateObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts usingBlock:(void (__attribute__((noescape)) ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block __attribute__((availability(macosx,introduced=10_6)));

// - (NSUInteger)indexOfObjectPassingTest:(BOOL (__attribute__((noescape)) ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(macosx,introduced=10_6)));
// - (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (__attribute__((noescape)) ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(macosx,introduced=10_6)));
// - (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts passingTest:(BOOL (__attribute__((noescape))^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(macosx,introduced=10_6)));

// - (NSIndexSet *)indexesOfObjectsPassingTest:(BOOL (__attribute__((noescape)) ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(macosx,introduced=10_6)));
// - (NSIndexSet *)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (__attribute__((noescape)) ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(macosx,introduced=10_6)));
// - (NSIndexSet *)indexesOfObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts passingTest:(BOOL (__attribute__((noescape)) ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(macosx,introduced=10_6)));

// - (NSArray<ObjectType> *)sortedArrayUsingComparator:(NSComparator __attribute__((noescape)))cmptr __attribute__((availability(macosx,introduced=10_6)));
// - (NSArray<ObjectType> *)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator __attribute__((noescape)))cmptr __attribute__((availability(macosx,introduced=10_6)));

typedef NSUInteger NSBinarySearchingOptions; enum {
    NSBinarySearchingFirstEqual = (1UL << 8),
    NSBinarySearchingLastEqual = (1UL << 9),
    NSBinarySearchingInsertionIndex = (1UL << 10),
};

// - (NSUInteger)indexOfObject:(ObjectType)obj inSortedRange:(NSRange)r options:(NSBinarySearchingOptions)opts usingComparator:(NSComparator __attribute__((noescape)))cmp __attribute__((availability(macosx,introduced=10_6)));

/* @end */


// @interface NSArray<ObjectType> (NSArrayCreation)

// + (instancetype)array;
// + (instancetype)arrayWithObject:(ObjectType)anObject;
// + (instancetype)arrayWithObjects:(const ObjectType [])objects count:(NSUInteger)cnt;
// + (instancetype)arrayWithObjects:(ObjectType)firstObj, ... __attribute__((sentinel(0,1)));
// + (instancetype)arrayWithArray:(NSArray<ObjectType> *)array;

// - (instancetype)initWithObjects:(ObjectType)firstObj, ... __attribute__((sentinel(0,1)));
// - (instancetype)initWithArray:(NSArray<ObjectType> *)array;
// - (instancetype)initWithArray:(NSArray<ObjectType> *)array copyItems:(BOOL)flag;

// + (nullable NSArray<ObjectType> *)arrayWithContentsOfFile:(NSString *)path;
// + (nullable NSArray<ObjectType> *)arrayWithContentsOfURL:(NSURL *)url;
// - (nullable NSArray<ObjectType> *)initWithContentsOfFile:(NSString *)path;
// - (nullable NSArray<ObjectType> *)initWithContentsOfURL:(NSURL *)url;

/* @end */


// @interface NSArray<ObjectType> (NSDeprecated)



// - (void)getObjects:(ObjectType __attribute__((objc_ownership(none))) [])objects __attribute__((availability(swift, unavailable, message="Use 'as [AnyObject]' instead")));

/* @end */





#ifndef _REWRITER_typedef_NSMutableArray
#define _REWRITER_typedef_NSMutableArray
typedef struct objc_object NSMutableArray;
typedef struct {} _objc_exc_NSMutableArray;
#endif

struct NSMutableArray_IMPL {
    struct NSArray_IMPL NSArray_IVARS;
};


// - (void)addObject:(ObjectType)anObject;
// - (void)insertObject:(ObjectType)anObject atIndex:(NSUInteger)index;
// - (void)removeLastObject;
// - (void)removeObjectAtIndex:(NSUInteger)index;
// - (void)replaceObjectAtIndex:(NSUInteger)index withObject:(ObjectType)anObject;
// - (instancetype)init __attribute__((objc_designated_initializer));
// - (instancetype)initWithCapacity:(NSUInteger)numItems __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSMutableArray<ObjectType> (NSExtendedMutableArray)

// - (void)addObjectsFromArray:(NSArray<ObjectType> *)otherArray;
// - (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
// - (void)removeAllObjects;
// - (void)removeObject:(ObjectType)anObject inRange:(NSRange)range;
// - (void)removeObject:(ObjectType)anObject;
// - (void)removeObjectIdenticalTo:(ObjectType)anObject inRange:(NSRange)range;
// - (void)removeObjectIdenticalTo:(ObjectType)anObject;
// - (void)removeObjectsFromIndices:(NSUInteger *)indices numIndices:(NSUInteger)cnt __attribute__((availability(macosx,introduced=10_0,deprecated=10_6,message="" )));
// - (void)removeObjectsInArray:(NSArray<ObjectType> *)otherArray;
// - (void)removeObjectsInRange:(NSRange)range;
// - (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(NSArray<ObjectType> *)otherArray range:(NSRange)otherRange;
// - (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(NSArray<ObjectType> *)otherArray;
// - (void)setArray:(NSArray<ObjectType> *)otherArray;
// - (void)sortUsingFunction:(NSInteger (__attribute__((noescape)) *)(ObjectType, ObjectType, void * _Nullable))compare context:(nullable void *)context;
// - (void)sortUsingSelector:(SEL)comparator;

// - (void)insertObjects:(NSArray<ObjectType> *)objects atIndexes:(NSIndexSet *)indexes;
// - (void)removeObjectsAtIndexes:(NSIndexSet *)indexes;
// - (void)replaceObjectsAtIndexes:(NSIndexSet *)indexes withObjects:(NSArray<ObjectType> *)objects;

// - (void)setObject:(ObjectType)obj atIndexedSubscript:(NSUInteger)idx __attribute__((availability(macosx,introduced=10_8)));

// - (void)sortUsingComparator:(NSComparator __attribute__((noescape)))cmptr __attribute__((availability(macosx,introduced=10_6)));
// - (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator __attribute__((noescape)))cmptr __attribute__((availability(macosx,introduced=10_6)));

/* @end */


// @interface NSMutableArray<ObjectType> (NSMutableArrayCreation)

// + (instancetype)arrayWithCapacity:(NSUInteger)numItems;

// + (nullable NSMutableArray<ObjectType> *)arrayWithContentsOfFile:(NSString *)path;
// + (nullable NSMutableArray<ObjectType> *)arrayWithContentsOfURL:(NSURL *)url;
// - (nullable NSMutableArray<ObjectType> *)initWithContentsOfFile:(NSString *)path;
// - (nullable NSMutableArray<ObjectType> *)initWithContentsOfURL:(NSURL *)url;

/* @end */


int main(int argc, char * argv[]) {
    NSArray *array = ((NSArray *(*)(Class, SEL, const ObjectType *, NSUInteger))(void *)objc_msgSend)(objc_getClass("NSArray"), sel_registerName("arrayWithObjects:count:"), (const id *)__NSContainer_literal(3U, ((NSNumber *(*)(Class, SEL, int))(void *)objc_msgSend)(objc_getClass("NSNumber"), sel_registerName("numberWithInt:"), 1), ((NSNumber *(*)(Class, SEL, int))(void *)objc_msgSend)(objc_getClass("NSNumber"), sel_registerName("numberWithInt:"), 2), ((NSNumber *(*)(Class, SEL, int))(void *)objc_msgSend)(objc_getClass("NSNumber"), sel_registerName("numberWithInt:"), 3)).arr, 3U);
    {
        NSNumber * number;
        struct __objcFastEnumerationState enumState = { 0 };
        id __rw_items[16];
        id l_collection = (id) array;
        _WIN_NSUInteger limit =
        ((_WIN_NSUInteger (*) (id, SEL, struct __objcFastEnumerationState *, id *, _WIN_NSUInteger))(void *)objc_msgSend)
        ((id)l_collection,
         sel_registerName("countByEnumeratingWithState:objects:count:"),
         &enumState, (id *)__rw_items, (_WIN_NSUInteger)16);
        if (limit) {
            unsigned long startMutations = *enumState.mutationsPtr;
            do {
                unsigned long counter = 0;
                do {
                    if (startMutations != *enumState.mutationsPtr)
                        objc_enumerationMutation(l_collection);
                    number = (NSNumber *)enumState.itemsPtr[counter++]; {
                        if (((BOOL (*)(id, SEL, NSNumber *))(void *)objc_msgSend)((id)number, sel_registerName("isEqualToNumber:"), ((NSNumber *(*)(Class, SEL, int))(void *)objc_msgSend)(objc_getClass("NSNumber"), sel_registerName("numberWithInt:"), 1))) {
                            goto __continue_label_1;
                        }
                        NSLog((NSString *)&__NSConstantStringImpl__var_folders_xk_3y8751nj20gg8q246mkyz1x00000gn_T_fastEnumeration_e94cb1_mi_0, number);
                        goto __break_label_1;
                    };
                __continue_label_1: ;
                } while (counter < limit);
            } while ((limit = ((_WIN_NSUInteger (*) (id, SEL, struct __objcFastEnumerationState *, id *, _WIN_NSUInteger))(void *)objc_msgSend)
                      ((id)l_collection,
                       sel_registerName("countByEnumeratingWithState:objects:count:"),
                       &enumState, (id *)__rw_items, (_WIN_NSUInteger)16)));
            number = ((NSNumber *)0);
        __break_label_1: ;
        }
        else
            number = ((NSNumber *)0);
    }
    
}
static struct IMAGE_INFO { unsigned version; unsigned flag; } _OBJC_IMAGE_INFO = { 0, 2 };
