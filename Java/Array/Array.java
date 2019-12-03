// package array;

public class Array {
    // 定以整型数据data 保存数据
    public int data[];
    // 定以数据的长度
    private int n;
    // 定以数组中实际个数
    private int count;

    // 构造方法，指定数组的大小
    public Array(int capacity) {
        this.data = new int[capacity];
        this.n = capacity;
        // 开始时一个数据都没有
        this.count = 0;
    }

    // 根据索引，找到数据中的元素并返回
    public int get(int index) {
        if(index < 0 || index >= this.count) {
            return -1;
        }

        return data[index];
    }

    // 给出一个值，找到在数组中的位置，并返回索引
    // -1 表示没有找到
    public int find(int value) {
        int pos = -1;
        int index = 0;
        for(; index < this.count; ++ index){
            if(value == this.data[index]){
                pos = index;
                break;
            }
        }

        return pos;
    }

    public boolean insert(int index, int value) {
        // 数组空间已经满了
        if(this.count == n){
            System.out.println("没有可以插入的位置");
            return false;
        }

        // 位置不合法
        if(index < 0 || index > this.count){
            System.out.println("位置不合法");
            return false;
        }

        // 将index及以后的元素后移
        for(int i = this.count; i > index; --i) {
            this.data[i] = this.data[i - 1];
        }

        data[index] = value;
        ++ this.count;
        return true;
    }

    // 根据索引，删除数据中的元素
    public boolean delete(int index){
        // 位置不合法
        if(index < 0 || index >= count){
            System.out.println("位置不合法");
            return false;
        }

        // 将index 开始的每个元素向前移动一个位置
        for (int i = index + 1; i < this.count; ++ i){
            this.data[i -1] = this.data[i];
        }
        -- this.count;
        return true;
    }

    public void printAll(){
        for(int i = 0; i < this.count; ++ i){
            System.out.print(this.data[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        Array array = new Array(5);
        array.printAll();

        array.insert(0, 3);
        array.insert(0, 4);
        array.insert(1, 5);
        array.insert(3, 9);
        array.insert(3,10);

        System.out.println(array.find(4));
        array.delete(0);
        array.printAll();
    }

}
