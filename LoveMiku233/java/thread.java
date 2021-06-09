//@author LoveMiku233
//多线程实现
class thread1 implements Runnable { //通过Runnable接口实现多线程
    private Thread t;
    private String threadName;

    public thread1(String name){
        threadName=name;
        System.out.println("创建线程"+threadName);
    }
    @Override
    public void run(){
        int a=100;
        System.out.println(threadName+"线程运行");
        try {
            while(a>0){
                if(a%10==0)
                System.out.println("线程"+threadName+" a的值:"+a);
                t.sleep(50);
                a--;
            }
        }catch (InterruptedException e){
            System.out.println("线程"+threadName+"正在等待或者中断");
        }
        System.out.println("线程"+threadName+"退出");
    }
    public void start(){
        System.out.println("启动线程:"+threadName);
        if(t==null){
            t=new Thread(this,threadName);
            t.start();
        }
    }
}
class thread2 extends Thread{ //通过继承Thread类实现
    //必须重写run方法
    private Thread t;
    private String threadName;

    public thread2(String name){
        threadName=name;
        System.out.println("创建线程"+threadName);
    }
    @Override
    public void run(){
        int a=100;
        System.out.println(threadName+"线程运行");
        try {
            while(a>0){
                if(a%10==0)
                System.out.println("线程"+threadName+" a的值:"+a);
                t.sleep(50);
                a--;
            }
        }catch (InterruptedException e){
            System.out.println("线程"+threadName+"正在等待或者中断");
        }
        System.out.println("线程"+threadName+"退出");
    }
    public void start(){
        System.out.println("启动线程:"+threadName);
        if(t==null){
            t=new Thread(this,threadName);
            t.start();
        }
    }
}
public class thread{
    public static void main(String[] args){
        thread1 t1=new thread1("1");
        t1.start();

        thread2 t2=new thread2("2");
        t2.start();
    }
}
