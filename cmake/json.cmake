# ref: https://www.cnblogs.com/pandamohist/p/13699911.html
function(getjsonlib)
include(fetchcontent)
fetchcontent_declare(	json	#库名字
						GIT_REPOSITORY https://github.com/nlohmann/json.git	# 仓库地址
						GIT_TAG v3.10.4 # 库版本
						SOURCE_DIR ${CMAKE_SOURCE_DIR}/3rdparty/json # 指定库下载地址
						)

fetchcontent_makeavailable(json)	
endfunction(getjsonlib)

