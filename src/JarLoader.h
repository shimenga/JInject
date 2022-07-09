#pragma once

#include "jni_md.h"
#include <jni.h>
#include <jvmti.h>

struct JarLoader {
  public:
  /**
   * @return UrlClassLoader instance
   */
  static jobject loadJar(JNIEnv *env, jobject file);

  /**
   * @return false if failed to locate the main class
   */
  static bool tryInvokeMain(JNIEnv *env, jvmtiEnv *jvmtiEnv, jobject classLoader, jobject file);

private:
  static bool callJIAgentMain(JNIEnv *jniEnv, jvmtiEnv *jvmtiEnv, jclass klass);
  static bool callMain(JNIEnv *jniEnv, jclass klass);
  static jclass getClass(JNIEnv *jniEnv, jobject classLoader, jstring name);
};