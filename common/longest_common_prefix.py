# https://www.geeksforgeeks.org/longest-common-prefix-using-word-by-word-matching/

# A python3 Program to find the longest  
# common prefix 
  
# A Utility Function to find the common  
# prefix between strings- str1 and str2 
def commonPrefixUtil(str1, str2): 
  
    result = ""; 
    n1 = len(str1) 
    n2 = len(str2) 
  
    # Compare str1 and str2 
    i = 0
    j = 0
    while i <= n1 - 1 and j <= n2 - 1: 
      
        if (str1[i] != str2[j]): 
            break
              
        result += str1[i] 
        i += 1
        j += 1
  
    return (result) 
  
# A Function that returns the longest  
# common prefix from the array of strings 
def commonPrefix (arr, n): 
  
    prefix = arr[0] 
  
    for i in range (1, n): 
        prefix = commonPrefixUtil(prefix, arr[i]) 
  
    return (prefix) 
  
# Driver Code 
if __name__ =="__main__": 
  
    arr = ["geeksforgeeks", "geeks", 
                    "gesk", "geezer"] 
    n = len(arr) 
  
    ans = commonPrefix(arr, n) 
  
    if (len(ans)): 
        print ("The longest common prefix is -", 
                ans); 
    else: 
        print("There is no common prefix") 
  
# This code is contributed by ita_c 

