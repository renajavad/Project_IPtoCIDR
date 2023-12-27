#include <string>
#include <vector>
#include <cmath>
#include <cstdint>

class IPtoCIDR 
{
public:

    std::vector<std::string> finalResult(std::string IP, int n) 
    {
        uint32_t IPint = StringtoInt(IP);
        std::vector <std::string> res;
        int z;
        int new_n;
        int prefix;
        
        while(n > 0)
        {
            z = countZeros(IPint);
            if(n >= pow(2,z))
            {
                new_n = pow(2,z);
                prefix = 32 - z;
            }
            else
            {
               int i = 0;
                while(pow(2,i) <= n)
                {
					 i++;
				}
                i--;
                new_n = pow(2,i);
                prefix = 32 - i;
            }
            res.push_back(InttoString(IPint) + "/" + std::to_string(prefix));
            n -= new_n;
            IPint += new_n;
        
        }
        return res;   
    }
    
    uint32_t StringtoInt(std::string IP)
    {
        std::string octet;
        int i = 3;
        uint32_t res = 0;
        for(auto c: IP)
        {
            if(c == '.')
            {
                res += stoi(octet)*pow(256,i); 
                i--;
                octet = std::string(); 
            }
            else
                octet.push_back(c);
        }
        res += stoi(octet)*pow(256,i);
        return res;  
    }
    
     int countZeros(uint32_t IP)
    { 
        int res = 0;
        uint32_t i = 1;
        while(!(IP & i))
        {
            i <<= 1;
            res++;  
        }
        return res; 
    }
    
    std::string InttoString(uint32_t IP)
    {
        std::string res;
        for(int i = 3; i >= 0; i--)
        {
            if(i == 3)
            {
                res += std::to_string(((IP >> i*8) & 255));
			}
            else
            {
                res += ("." + std::to_string(((IP >> i*8) & 255)));
			}
		}
        return res;
    }
};



