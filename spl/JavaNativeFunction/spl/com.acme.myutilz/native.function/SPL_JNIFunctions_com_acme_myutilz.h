// DO NOT EDIT THIS FILE - it is machine generated
#ifndef SPL_JNIFunctions_com_acme_myutilz_h
#define SPL_JNIFunctions_com_acme_myutilz_h

#include <SPL/Runtime/Function/SPLJavaFunction.h>
#include <SPL/Runtime/Type/SPLType.h>

namespace SPL {
namespace JNIFunctions {
namespace com {
namespace acme {
namespace myutilz {
class SPL_JNIFunctions {
public:

// Generated from MyJavaFunctions in impl/java/bin/MyJavaFunctions$StreamsModel.class at Mon Feb 08 18:35:07 UTC 2021
static SPL::int32 cumulativeAdd(SPL::int32 const & arg1, SPL::int32 const & arg2) {
    static __thread void *func;
    static __thread jclass classGlobalRef;
    static __thread jmethodID mid;
    if (func == NULL) {
        func = SPL::SPLJavaFunction::loadFunction("JavaNativeFunctions", "1.0.1", SPLJAVAFUNCTION_ADL_FILENAME, "impl/java/bin", "MyJavaFunctions", "cumulativeAdd", "(II)I", "com.acme.myutilz", "public int32 cumulativeAdd(int32 a, int32 b)", &classGlobalRef, &mid);
    }
    JNIEnv* env = SPL::SPLJavaFunction::getJNIEnv(func);
    SPL::int32 result = env->CallStaticIntMethod(classGlobalRef, mid, arg1, arg2);
    if (env->ExceptionCheck())
        SPL::SPLJavaFunction::throwCallError(func);
    return result;
}

// Generated from MyJavaFunctions in impl/java/bin/MyJavaFunctions$StreamsModel.class at Mon Feb 08 18:35:07 UTC 2021
static SPL::uint32 cumulativeAdd(SPL::uint32 const & arg1, SPL::uint32 const & arg2) {
    SPL::int32 result = cumulativeAdd((SPL::int32) arg1, (SPL::int32) arg2);
    return (SPL::uint32) result;
}

// Generated from MyJavaFunctions in impl/java/bin/MyJavaFunctions$StreamsModel.class at Mon Feb 08 18:35:07 UTC 2021
static SPL::int32 intArrayLength(SPL::list<int32> const & arg1) {
    static __thread void *func;
    static __thread jclass classGlobalRef;
    static __thread jmethodID mid;
    if (func == NULL) {
        func = SPL::SPLJavaFunction::loadFunction("JavaNativeFunctions", "1.0.1", SPLJAVAFUNCTION_ADL_FILENAME, "impl/java/bin", "MyJavaFunctions", "intArrayLength", "([I)I", "com.acme.myutilz", "public int32 intArrayLength(list<int32> a)", &classGlobalRef, &mid);
    }
    JNIEnv* env = SPL::SPLJavaFunction::getJNIEnv(func);
    jsize len1 = arg1.getSize();
    jintArray obj1 = env->NewIntArray(len1);
    if (obj1 == NULL)
        SPL::SPLJavaFunction::throwCreateError(func);
    if (len1 > 0) {
        env->SetIntArrayRegion(obj1, 0, len1, (jint *) &(arg1.at(0)));
        if (env->ExceptionCheck())
            SPL::SPLJavaFunction::throwCreateError(func);
        }
    SPL::int32 result = env->CallStaticIntMethod(classGlobalRef, mid, obj1);
    if (env->ExceptionCheck())
        SPL::SPLJavaFunction::throwCallError(func);
    env->DeleteLocalRef(obj1);
    return result;
}

// Generated from MyJavaFunctions in impl/java/bin/MyJavaFunctions$StreamsModel.class at Mon Feb 08 18:35:07 UTC 2021
template <SPL::int32 lsize>
static SPL::int32 intArrayLength(SPL::blist<int32, lsize> const & arg1) {
    SPL::int32 result = intArrayLength((SPL::list<int32>) arg1);
    return result;
}

// Generated from MyJavaFunctions in impl/java/bin/MyJavaFunctions$StreamsModel.class at Mon Feb 08 18:35:07 UTC 2021
static SPL::uint32 intArrayLength(SPL::list<uint32> const & arg1) {
    SPL::int32 result = intArrayLength((SPL::list<int32>) arg1);
    return (SPL::uint32) result;
}

// Generated from MyJavaFunctions in impl/java/bin/MyJavaFunctions$StreamsModel.class at Mon Feb 08 18:35:07 UTC 2021
template <SPL::int32 lsize>
static SPL::uint32 intArrayLength(SPL::blist<uint32, lsize> const & arg1) {
    SPL::uint32 result = intArrayLength((SPL::list<uint32>) arg1);
    return result;
}

// Generated from MyJavaFunctions in impl/java/bin/MyJavaFunctions$StreamsModel.class at Mon Feb 08 18:35:07 UTC 2021
static SPL::list<float64> getDoubleArray() {
    static __thread void *func;
    static __thread jclass classGlobalRef;
    static __thread jmethodID mid;
    if (func == NULL) {
        func = SPL::SPLJavaFunction::loadFunction("JavaNativeFunctions", "1.0.1", SPLJAVAFUNCTION_ADL_FILENAME, "impl/java/bin", "MyJavaFunctions", "getDoubleArray", "()[D", "com.acme.myutilz", "public list<float64> getDoubleArray()", &classGlobalRef, &mid);
    }
    JNIEnv* env = SPL::SPLJavaFunction::getJNIEnv(func);
    jdoubleArray resObj = (jdoubleArray) env->CallStaticObjectMethod(classGlobalRef, mid);
    if (env->ExceptionCheck())
        SPL::SPLJavaFunction::throwCallError(func);
    if (resObj != NULL) {
        jdouble *elems = env->GetDoubleArrayElements(resObj, NULL);
        if (elems == NULL)
            SPL::SPLJavaFunction::throwCreateError(func);
        SPL::list<float64> result(elems, elems + env->GetArrayLength(resObj));
        env->ReleaseDoubleArrayElements(resObj, elems, JNI_ABORT);
        env->DeleteLocalRef(resObj);
        return result;
    } else {
        return SPL::list<float64>();
    }
}

};
}
}
}
}
}
#endif
