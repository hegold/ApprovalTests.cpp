#pragma once

#include "ApprovalTests/core/ApprovalNamer.h"
#include <vector>
#include <stdexcept>

namespace ApprovalTests
{
    class TestName
    {
    public:
        const std::string& getFileName() const;

        void setFileName(const std::string& file);

    private:
        static void checkBuildConfiguration(const std::string& fileName);

    public:
        static std::string getMisconfiguredBuildHelp(const std::string& fileName);
        std::string checkParentDirectoriesForFile(const std::string& file);

        std::vector<std::string> sections;
        static std::string directoryPrefix;

    private:
        std::string handleBoostQuirks() const;
        std::string findFileName(const std::string& file);

        std::string fileName;
    };

    class TestConfiguration
    {
    public:
        std::string subdirectory;
    };

    class ApprovalTestNamer : public ApprovalNamer
    {
    private:
    public:
        ApprovalTestNamer() = default;

        std::string getTestName() const;

        static bool isForbidden(char c);

        static std::string convertToFileName(const std::string& fileName);

        static TestName& getCurrentTest();

        static std::string getMisconfiguredMainHelp();

        // Deprecated - please use getSourceFileName
        std::string getFileName() const;

        std::string getSourceFileName() const;

        std::string getDirectory() const;

        static TestName& currentTest(TestName* value = nullptr);

        static TestConfiguration& testConfiguration();

        virtual std::string getApprovedFile(std::string extensionWithDot) const override;

        virtual std::string getReceivedFile(std::string extensionWithDot) const override;

        std::string getOutputFileBaseName() const;

        std::string getFullFileName(const std::string& approved,
                                    const std::string& extensionWithDot) const;
    };
}
