#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <iomanip>

void skew_py2cpp_same()
{
    std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ <<  std::endl;
    std::vector<double> data = {8.052654, 8.052684, 8.052669, 8.052669, 8.052637,
                                    8.052722, 8.052827, 8.053102, 8.053072, 8.053046,
                                    8.053046, 8.05307,  8.053034, 8.052705, 8.052578,
                                    8.052739, 8.052811, 8.052781, 8.052781, 8.052519
                                    /* ... more data ... */};

        auto count = data.size();

        double data_mean = 0.0;
        double data_sum = 0.0;
        for(auto i = 0; i < data.size(); ++i)
        {
            data_sum += data.at(i);
        }
        data_mean = data_sum / count;

        std::vector<double> adjusted(data.size(),0.0);
        for(auto i = 0; i < data.size(); ++i)
        {
            adjusted.at(i) = data.at(i) - data_mean;
        }

        std::vector<double> adjusted2(data.size(),0.0);
        std::vector<double> adjusted3(data.size(),0.0);
        for(auto i = 0; i < data.size(); ++i)
        {
            adjusted2.at(i) = pow(adjusted.at(i),2);
            adjusted3.at(i) = pow(adjusted.at(i),3);
        }

        double m2 = 0.0;
        double m3 = 0.0;
        for(auto i = 0; i < adjusted.size(); ++i)
        {
            m2 += adjusted2.at(i);
            m3 += adjusted3.at(i);
        }


        double coef = (count * std::sqrt(1.0 * (count - 1)))  / (count - 2) * 1.0;
        double result = coef * (m3 / std::pow(m2,1.5));  // 计算结果和python一致

        std::cout << "data_mean : " << data_mean << std::endl; // result : 0.430583
        std::cout << "m2 : " << m2 << std::endl;               // result : 0.430583
        std::cout << "m3 : " << m3 << std::endl;               // result : 0.430583
        std::cout << "coef : " << coef << std::endl;           // result : 0.430583
        std::cout << "result : " << result << std::endl;       // result : 0.430583
}

void skew_py2cpp_op()
{
    std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ <<  std::endl;
    std::vector<double> data = {8.052654, 8.052684, 8.052669, 8.052669, 8.052637,
                                    8.052722, 8.052827, 8.053102, 8.053072, 8.053046,
                                    8.053046, 8.05307,  8.053034, 8.052705, 8.052578,
                                    8.052739, 8.052811, 8.052781, 8.052781, 8.052519
                                    /* ... more data ... */};

        auto count = data.size();

        double data_sum = 0.0,data_sumXX,data_sumXXX;

        for(auto i = 0; i < data.size(); ++i)
        {
            data_sum += data.at(i);
            data_sumXX += pow(data.at(i),2);
            data_sumXXX += pow(data.at(i),3);
        }
        double data_mean = data_sum / count;

        double m2 = data_sumXX - 2 * data_sum * data_mean + count * data_mean * data_mean;
        double m3 = data_sumXXX - 3 * data_mean * data_sumXX + 3 * data_mean * data_mean * data_sum - count * pow(data_mean,3);

        std::cout << "data_sumXXX : " << data_sumXXX << std::endl;
        std::cout << "3 * data_mean * data_sumXX : " << 3 * data_mean * data_sumXX << std::endl;
        std::cout << "3 * data_mean * data_mean * data_sum : " << 3 * data_mean * data_mean * data_sum << std::endl;
        std::cout << "count * pow(data_mean,3) : " << count * pow(data_mean,3) << std::endl;

        double coef = (count * std::sqrt(1.0 * (count - 1)))  / (count - 2) * 1.0;
        double result = coef * (m3 / std::pow(m2,1.5));  // 计算结果和python一致

        std::cout << "data_mean : " << data_mean << std::endl; // result : 0.430583
        std::cout << "m2 : " << m2 << std::endl;               // result : 0.430583
        std::cout << "m3 : " << m3 << std::endl;               // result : 0.430583
        std::cout << "coef : " << coef << std::endl;           // result : 0.430583
        std::cout << "result : " << result << std::endl;       // result : 0.430583
}


int main() {
    // std::cout << std::fixed << std::setprecision(12);
    skew_py2cpp_same();
    skew_py2cpp_op();
    return 0;
}
