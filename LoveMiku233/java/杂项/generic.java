//泛型测试
//@author LoveMiku233
public class generic {
    public static <E> void printArray(E[] arr){
        if(arr instanceof Integer[]) {  //instanceof 比较两个对象
            for (E i : arr) {
                System.out.printf("%s ", i);
            }
        }else if(arr instanceof Character[]){
            for(E i:arr){
                System.out.print(i);
            }
            System.out.println();
        }
        System.out.println();
    }
    public static void main(String[] args){
        Integer[] arr={1,2,3,4,5};
        Character[] str={'a','b','c','d'};
        printArray(arr);
        printArray(str);
    }
}
