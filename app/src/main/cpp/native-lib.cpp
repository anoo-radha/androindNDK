#include <jni.h>
#include <string>
#include <android/log.h>

extern "C"
jstring
Java_com_anuradha_ndkapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */,
        jstring inJNIStr,
        jint input_num) {
    std::string hello = "Hello from C++";

    const char *inCStr = (env)->GetStringUTFChars(inJNIStr,NULL);
    if (NULL == inCStr) return NULL;

    //getting part of the input string
    char outCStr[128];
    (env)->GetStringUTFRegion(inJNIStr, 2,3,outCStr);

    //halfing the input number by right shifting
    input_num >>= 1;
    //To redirect print message to Log.i
    __android_log_print(ANDROID_LOG_INFO, "stringFromJNI", "halfed number is: %d", input_num);

//    return env->NewStringUTF(hello.c_str());
    return env->NewStringUTF(outCStr);
}
