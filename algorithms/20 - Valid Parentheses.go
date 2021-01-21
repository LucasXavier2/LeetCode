func isValid(s string) bool {
    
    var stack []byte
    
    for i := 0; i < len(s); i++ {
        var char byte = s[i]
        
        if (len(stack) != 0) {
            top := stack[len(stack)-1]
            
            if (char == '}' && top == '{') {
                stack = stack[:len(stack)-1] 
                continue
            } else if (char == ']' && top == '[') {
                stack = stack[:len(stack)-1] 
                continue
            } else if (char == ')' && top == '(') {
                stack = stack[:len(stack)-1]
                continue
            }   
        }
        stack = append(stack, char)   
    } 
    
    if (len(stack) != 0) { 
        return false
    }
    
    return true
}
 