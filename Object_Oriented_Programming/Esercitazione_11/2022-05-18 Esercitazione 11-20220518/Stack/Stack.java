import java.util.ArrayList;

public class Stack<T> {

    private ArrayList<T> stack = new ArrayList<>();

    public boolean push(T element) {

        if(stack.add(element))
            return true;
        
        return false;
    }

    public T pop() {

        return stack.remove(stack.size() - 1); 
    } 
}