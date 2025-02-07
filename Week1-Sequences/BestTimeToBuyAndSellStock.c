int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;
    for(int i = 0; i < pricesSize; i++){
        int buy = prices[i];
        for(int j = i+1; j < pricesSize; j++){

            int sell = prices[j];
            int profit = sell - buy;
            profit = profit > 0? profit : 0;
            maxProfit = profit > maxProfit ? profit : maxProfit;
            
        }
    }
    return maxProfit;
}
