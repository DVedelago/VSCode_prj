#include <iostream>
#include <string_view>

struct AdsRevenue
{
    int ads_shown {};
    double ads_clicked {};
    double avg_earns {};
};

AdsRevenue adsParameterInput()
{
    AdsRevenue temp;
    std::cout << "How many ads were shown today? ";
    std::cin >> temp.ads_shown;
    
    std::cout << "What percentage of them were clicked on? ";
    std::cin >> temp.ads_clicked;

    std::cout << "What's the average earnings per click? ";
    std::cin >> temp.avg_earns;

    return temp;
}

void printAds(const AdsRevenue& ad)
{
    std::cout << "Today " << ad.ads_shown << " ads were shown, ";
    std::cout << (ad.ads_clicked*100) << "% of them were clicked and ";
    std::cout << ad.avg_earns << " is the average earning on them. \n";

    std::cout << (ad.ads_clicked*ad.ads_shown*ad.avg_earns/100) << " is the total earning in $. \n";
}

int main()
{
    AdsRevenue todayAd { adsParameterInput() };
    printAds(todayAd);

    return 0;
}
