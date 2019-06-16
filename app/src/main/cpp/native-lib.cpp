#include <jni.h>
#include <string>
#include <array>
#include <boost/filesystem.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_body_boosttest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_body_boosttest_MainActivity_runBoost(JNIEnv *env, jobject thiz) {
    std::array<char, 2> firstTwoBytes {};
    boost::iostreams::filtering_istream in;
    in.push(boost::iostreams::gzip_decompressor());
    in.push(boost::iostreams::file_descriptor_source("/sdcard/testFile.gz"));
    in.read(firstTwoBytes.data(), 2);
}