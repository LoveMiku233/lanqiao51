package 简单登录系统;
//物品
public class item implements Comparable{
    private int price;  //价格
    private String name;  //物品名称

    public item(int price, String name) {
        this.price = price;
        this.name = name;
    }
    public item(){
        this.price = 0;
        this.name = "NULL";
    }

    public int compareTo(Object o){
        item i=(item)o;
        if(i.getPrice()>this.getPrice())return -1;
        if(i.getPrice()<this.getPrice())return 1;
        return 0;
    }


    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    public String printinto(){
        return  "物品名称:"+this.name+" 物品价格: "+this.price;
    }
}
