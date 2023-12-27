#include "IPtoCidr.cpp"
#include <gtest/gtest.h>
#include <vector>
#include <fstream>

IPtoCIDR cidr;

std::string IP1 = "255.0.0.7";
std::vector<std::string> res1 = { "255.0.0.7/32", "255.0.0.8/29", "255.0.0.16/32" };

std::string IP2 = "117.145.102.62";
std::vector<std::string> res2 = { "117.145.102.62/31", "117.145.102.64/30", "117.145.102.68/31" };

TEST(cidr, IPtoCIDRTest)
{
	ASSERT_EQ(res1, cidr.finalResult(IP1, 10));
	ASSERT_EQ(res2, cidr.finalResult(IP2, 8));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
    IPtoCIDR cidr;
    std::string IP;
    int n;

    std::ifstream in("input_IP.txt");
    if (in.is_open())
    {
        std::getline(in, IP);
        in >> n;

    }

    in.close();

    std::vector<std::string> res = cidr.finalResult(IP, n);

    std::ofstream out("output_IP.txt");

    if (out.is_open())
    {
        out << "CIDR blocks: ";
        for (std::string s : res)
        {
            out << '"' << s << '"' << " ";
        }

    }

    out.close();


	return RUN_ALL_TESTS();
}