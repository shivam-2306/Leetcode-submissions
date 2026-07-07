/**
 * @param {number} n
 * @return {number}
 */
var sumAndMultiply = function(n) {
    const value = n.toString().split("");
    let total = 0;
    let number = '';
    for(const ele of value){
        total += Number(ele)
        if(Number(ele)!= 0){
            number+= ele;
        } 
    }
    return total*Number(number);
};