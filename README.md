# Описание алгоритма  

Создаётся класс под названием IPtoCIDR, который преобразует IP-адрес в список блоков CIDR.  
В классе создаются публичные функции-члены :  
1. std::vector<std::string> finalResult(std::string IP, int n)
2. uint32_t StringtoInt(std::string IP)  
3. int countZeros(uint32_t IP)  
4. std::string InttoString(uint32_t IP)

Функция finalResult(std::string IP, int n) принимает IP-адрес в качестве входных данных и количество требуемых блоков и возвращает вектор строк, представляющих блоки CIDR.
Внутри этой функции в начале вызывается функция StringtoInt(IP), которая преобразует строковое представление IP-адреса в эквивалентную ему целочисленную форму.  
Далее в цикле while вызывается функция countZeros(IPint), которая подсчитывает количество последовательных нулей в двоичном представлении данного IP-адреса.  
Внутри цикла считывается префикс (prefix) CIDR блока и вызывается функция InttoString(IPint), которая преобразует 32-разрядный целочисленный IP-адрес в его строковое представление.  
Результат записывается в вектор строк через символ "/".