#include <jni.h>
#include <string>

extern "C"
jstring
Java_com_anuradha_ndkapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */,
        jstring inJNIStr) {
    std::string hello = "Hello from C++";

    const char *inCStr = (env)->GetStringUTFChars(inJNIStr,NULL);
    if (NULL == inCStr) return NULL;

//    return env->NewStringUTF(hello.c_str());
    return env->NewStringUTF(inCStr);
}
