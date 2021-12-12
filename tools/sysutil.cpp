#include <string>
#include <windows.h>

#pragma comment(lib, "version.lib")

bool QueryValue(const std::string &ValueName, const std::string &szModuleName,
                std::string &RetStr)
{
    bool bSuccess = FALSE;
    BYTE *m_lpVersionData = NULL;
    DWORD m_dwLangCharset = 0;
    CHAR *tmpstr = NULL;
    do
    {
        if (!ValueName.size() || !szModuleName.size())
        {
            break;
        }
        DWORD dwHandle;
        // 判断系统能否检索到指定文件的版本信息
        //针对包含了版本资源的一个文件，判断容纳 文件版本信息需要一个多大的缓冲区
        //返回值说明Long，容纳文件的版本资源所需的缓冲区长度。如文件不包含版本信息，则返回一个0值。会设置GetLastError参数表
        DWORD dwDataSize = ::GetFileVersionInfoSizeA((LPCSTR)szModuleName.c_str(),
                                                     &dwHandle);
        if (dwDataSize == 0)
        {
            break;
        }
        // std::nothrow:在内存不足时，new (std::nothrow)并不抛出异常，而是将指针置NULL。
        m_lpVersionData = new (std::nothrow) BYTE[dwDataSize]; // 分配缓冲区
        if (NULL == m_lpVersionData)
        {
            break;
        }
        // 检索信息
        //从支持版本标记的一个模块里获取文件版本信息
        if (!::GetFileVersionInfoA((LPCSTR)szModuleName.c_str(), dwHandle, dwDataSize,
                                   (void *)m_lpVersionData))
        {
            break;
        }
        UINT nQuerySize;
        DWORD *pTransTable;
        if (!::VerQueryValueA(m_lpVersionData, "\\VarFileInfo\\Translation",
                              (void **)&pTransTable, &nQuerySize))
        {
            break;
        }
        // MAKELONG 将两个16位的数联合成一个无符号的32位数
        m_dwLangCharset = MAKELONG(HIWORD(pTransTable[0]), LOWORD(pTransTable[0]));
        if (m_lpVersionData == NULL)
        {
            break;
        }
        tmpstr = new (std::nothrow) CHAR[128]; // 分配缓冲区
        if (NULL == tmpstr)
        {
            break;
        }
        sprintf_s(tmpstr, 128, "\\StringFileInfo\\%08lx\\%s", m_dwLangCharset,
                  ValueName.c_str());
        LPVOID lpData;
        // 调用此函数查询前需要先依次调用函数GetFileVersionInfoSize和GetFileVersionInfo
        if (::VerQueryValueA((void *)m_lpVersionData, tmpstr, &lpData, &nQuerySize))
        {
            RetStr = (char *)lpData;
        }
        bSuccess = TRUE;
    } while (FALSE);
    // 销毁缓冲区
    if (m_lpVersionData)
    {
        delete[] m_lpVersionData;
        m_lpVersionData = NULL;
    }
    if (tmpstr)
    {
        delete[] tmpstr;
        tmpstr = NULL;
    }
    return bSuccess;
}

//获取文件说明
bool GetFileDescription(const std::string &szModuleName, std::string &RetStr)
{
    return QueryValue("FileDescription", szModuleName, RetStr);
}

//获取文件版本
bool GetFileVersion(const std::string &szModuleName, std::string &RetStr)
{
    return QueryValue("FileVersion", szModuleName, RetStr);
}
//获取内部名称
bool GetInternalName(const std::string &szModuleName, std::string &RetStr)
{
    return QueryValue("InternalName", szModuleName, RetStr);
}

//获取公司名称
bool GetCompanyName(const std::string &szModuleName, std::string &RetStr)
{
    return QueryValue("CompanyName", szModuleName, RetStr);
}

//获取版权
bool GetLegalCopyright(const std::string &szModuleName, std::string &RetStr)
{
    return QueryValue("LegalCopyright", szModuleName, RetStr);
}

//获取原始文件名
bool GetOriginalFilename(const std::string &szModuleName, std::string &RetStr)
{
    return QueryValue("OriginalFilename", szModuleName, RetStr);
}

//获取产品名称
bool GetProductName(const std::string &szModuleName, std::string &RetStr)
{
    return QueryValue("ProductName", szModuleName, RetStr);
}

//获取产品版本
bool GetProductVersion(const std::string &szModuleName, std::string &RetStr)
{
    return QueryValue("ProductVersion", szModuleName, RetStr);
}

bool getSystemVersion(std::string &ver)
{
    std::string vname;
    //先判断是否为win8.1或win10
    typedef void(__stdcall * NTPROC)(DWORD *, DWORD *, DWORD *);
    HINSTANCE hinst = LoadLibrary("ntdll.dll");
    DWORD dwMajor, dwMinor, dwBuildNumber;
    NTPROC proc = (NTPROC)GetProcAddress(hinst, "RtlGetNtVersionNumbers");
    proc(&dwMajor, &dwMinor, &dwBuildNumber);
    ver = std::to_string(dwMajor) + "." + std::to_string(dwMinor);
    if (ver == "6.3" || ver == "10.0")
        return 1;
    else
        ver = "";

    SYSTEM_INFO info;     //用SYSTEM_INFO结构判断64位AMD处理器
    GetSystemInfo(&info); //调用GetSystemInfo函数填充结构
    OSVERSIONINFOEX os;
    os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
#pragma warning(disable : 4996)
    if (GetVersionEx((OSVERSIONINFO *)&os))
    {
        ver = std::to_string(os.dwMajorVersion) + "." + std::to_string(os.dwMinorVersion);
        return 1;
    }
    else
        return 0;
}

int main()
{
    std::string ret;
    GetFileVersion("D:\\Project\\CPP\\cmake-template\\test\\DlpOCR.dll", ret);
    std::string ver;
    getSystemVersion(ver);
    printf("FileVersion=%s\tSystemVersion=%s\tFileEncoding=%d\n", ret.c_str(), ver.c_str(), encoding);
    getchar();
    return 0;
}
