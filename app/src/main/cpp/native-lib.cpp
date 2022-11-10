#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_dconeybe_jnidemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jlong JNICALL
Java_dconeybe_jnidemo_MainActivity_add(JNIEnv *env, jclass clazz, jint num1, jlong num2) {
    return num1 + num2;
}

extern "C"
JNIEXPORT void JNICALL
Java_dconeybe_jnidemo_MainActivity_populateList(JNIEnv *env, jclass clazz, jobject list,
                                                jint count) {
  if (! list) {
    jclass npeClass = env->FindClass("java/lang/NullPointerException");
    if (! env->ExceptionCheck()) {
      env->ThrowNew(npeClass, "list==null");
    }
    return;
  }
  if (count < 0) {
    jclass iaeClass = env->FindClass("java/lang/IllegalArgumentException");
    if (! env->ExceptionCheck()) {
      env->ThrowNew(iaeClass, "invalid count");
    }
    return;
  }

  jclass integerClass = env->FindClass("java/lang/Integer");
  if (env->ExceptionCheck()) return;
  jmethodID integerConstructor = env->GetMethodID(integerClass, "<init>", "(I)V");
  if (env->ExceptionCheck()) return;

  jclass listClass = env->GetObjectClass(list);
  if (env->ExceptionCheck()) return;
  jmethodID addMethodId = env->GetMethodID(listClass, "add", "(Ljava/lang/Object;)Z");
  if (env->ExceptionCheck()) return;
  for (int i=0; i<count; i++) {
    jobject integerObject = env->NewObject(integerClass, integerConstructor, i);
    if (env->ExceptionCheck()) return;
    env->CallBooleanMethod(list, addMethodId, integerObject);
    if (env->ExceptionCheck()) return;
  }
}













