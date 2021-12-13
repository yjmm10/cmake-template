# ref: https://www.cnblogs.com/pandamohist/p/13699911.html
function(getgtestlib)
include(fetchcontent)
fetchcontent_declare(	googletest	#库名字
						GIT_REPOSITORY https://github.com/google/googletest.git	# 仓库地址
						GIT_TAG v1.10.x # 库版本
						SOURCE_DIR ${CMAKE_SOURCE_DIR}/3rdparty/googletest # 指定库下载地址
						)

fetchcontent_makeavailable(googletest)	
endfunction(getgtestlib)

