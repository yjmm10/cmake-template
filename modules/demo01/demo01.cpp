#include <glog/logging.h>

int main(int argc, char **argv)
{

    google::InitGoogleLogging(argv[0]);
    LOG(INFO) << "This is INFO log information";
    LOG(WARNING) << "This is WARNING log information";
    LOG(ERROR) << "This is ERROR log information";
    // LOG(FATAL) << "This is FATAL log information";

    LOG_IF(INFO, 1 < 2) << "This is true: 1 < 2. ";
    for (int i = 0; i < 100; ++i)
    {
        LOG_EVERY_N(INFO, 10) << "Log every 10 times. ";
    }

    CHECK(1 < 2) << "The world is end, because one is not less than  2. ";
    return 0;
}