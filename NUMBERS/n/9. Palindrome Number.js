function isPalindrome(x) {
    if (x < 0) {
        return false;
    }
    // Convert number to string
    const str = x.toString();
    const n = str.length;

    // Check characters from both ends
    for (let i = 0; i < Math.floor(n / 2); i++) {
        if (str[i] !== str[n - 1 - i]) {
            return false;
        }
    }

    return true;
}

console.log(isPalindrome(121));  
console.log(isPalindrome(-121)); 
console.log(isPalindrome(10));   