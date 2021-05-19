public class Item {
    String name;//名字
    int price;//价格
    public static void main(String[] args){
        Item BloodBottle = new Item();
        BloodBottle.name = "血瓶";
        BloodBottle.price = 50;

        Item StrawSandals = new Item();
        StrawSandals.name = "草鞋";
        StrawSandals.price = 300;

        Item SerratedDagger = new Item();
        SerratedDagger.name = "锯齿短匕";
        SerratedDagger.price = 1100;
    }
}
