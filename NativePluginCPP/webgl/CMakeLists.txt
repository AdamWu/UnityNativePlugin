# =========================
# Effekseer UnityPlugin for WebGL
# 
# ■ Emscripten と CMake のセットアップ＆ビルド方法について
# 参考 : https://gist.github.com/faithandbrave/9b3d439d135e63abdbe7
#
# ■ Unity WebGLプラグインから C++ 関数を呼び出す
# 参考 : http://docs.unity3d.com/ja/current/Manual/webgl-interactingwithbrowserscripting.html
#
# ■ 適用方法
# ビルドした EffekseerUnity.bc ファイルを "Assets\Plugins\WebGL" に追加する
# =========================

# プロジェクト名
project(Effekseer)

# CMake バージョンチェック
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++11" ${CMAKE_CXX_FLAGS})

# include 一覧を指定する
set(
	INCLUDE_DIR
	"${PROJECT_SOURCE_DIR}./../opengl"
	"${PROJECT_SOURCE_DIR}./../../../../Effekseer/Dev/Cpp/Effekseer"
	"${PROJECT_SOURCE_DIR}./../../../../Effekseer/Dev/Cpp/EffekseerRendererCommon"
	"${PROJECT_SOURCE_DIR}./../../../../Effekseer/Dev/Cpp/EffekseerRendererGL")
	
include_directories (${INCLUDE_DIR}) 

# OpenGL ES 2.0を有効にする
add_definitions(-D__EFFEKSEER_RENDERER_GLES2__)

# ソースファイル一覧を指定する
file(GLOB effekseer_src
	${PROJECT_SOURCE_DIR}./../../../../Effekseer/Dev/Cpp/Effekseer/*.cpp
	${PROJECT_SOURCE_DIR}./../../../../Effekseer/Dev/Cpp/Effekseer/Effekseer/*.cpp
	${PROJECT_SOURCE_DIR}./../../../../Effekseer/Dev/Cpp/EffekseerRendererCommon/*.cpp
	${PROJECT_SOURCE_DIR}./../../../../Effekseer/Dev/Cpp/EffekseerRendererGL/EffekseerRenderer/*.cpp
	${PROJECT_SOURCE_DIR}./../common/*.cpp
	${PROJECT_SOURCE_DIR}./../opengl/*.cpp)

# 使わないソースファイルを削除
# INTERNAL_LOADER
list(REMOVE_ITEM effekseer_src "${PROJECT_SOURCE_DIR}./../../../../Effekseer/Dev/Cpp/EffekseerRendererCommon/EffekseerRenderer.DXTK.DDSTextureLoader.cpp")
list(REMOVE_ITEM effekseer_src "${PROJECT_SOURCE_DIR}./../../../../Effekseer/Dev/Cpp/EffekseerRendererCommon/EffekseerRenderer.PngTextureLoader.cpp")

# 拡張子を指定する
set(CMAKE_SHARED_LIBRARY_SUFFIX ".bc")

# コンパイル先を追加
add_library(EffekseerUnity SHARED ${effekseer_src} )
