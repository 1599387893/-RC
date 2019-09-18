public class Array<E> {
	private E[] data;
	private int size;
	
	//构造函数
	public Array(int capacity) {
		data = (E[])new Object[capacity];
		size = 0;
	}
	
	//无参构造函数
	public Array() {
		this(10);
	}
	
	//获取数组的容量
	public int getCapacity() {
		return data.length;
	}
	
	//获取数组中的元素个数
	public int getSize() {
		return  size;
	}
	
	//返回数组是否为空
	public boolean isEmpty() {
		return (size==0);
	}
	
	//在index索引的位置插入一个新元素e
	public void add(int index,E e) {
		
		if(size == data.length)
			System.out.println("数组已满！");
		if(index < 0 || index > size)
			System.out.println("索引越界！");
		
		for(int i = size -1 ; i >= index; i--)
			data[i+1] = data[i];
		data[index] = e;
		size++;	
	}
	
	//向所有元素后添加一个新元素
	public void addLast(E e) {
		add(size,e);
	}
	
	//向所有元素前添加一个新元素
	public void addFrist(E e) {
		add(0,e);
	}
	
	//获取index索引位置的元素
	public E Get(int index) {
		if(index >= size || index < 0)
			System.out.println("index索引越界！");
		return data[index];
	}
	//修改index索引位置的元素为e
	public void set(int index,E e) {
		if(index > data.length || index < 0)
			System.out.println("index索引越界！");
		data[index] = e;
	}
	
	//查找数组中是否有元素e
	public boolean contains(E e) {
		if(find(e) != -1)
			return true;
		return false;
	}
	//查找数组中的元素e所在的索引，如果不存在元素e，则返回-1
	public int find(E e) {
		for(int i = 0;i<size;++i)
			if(data[i].equals(e))
				return i;
		return -1;
	}
	
	//从数组中删除index位置的元素，返回删除的元素
	public E remove(int index) {
		if(index < 0 || index > data.length)
			System.out.println("index索引越界！");
		E ret = data[index];
		for(int i = index-1; i >= 0;--i)
			data[i] = data[i+1];
		return ret;
	}
	
	//从数组中删除第一个元素，返回删除的元素
	public E removeFrist() {
		return remove(0);
	}
	
	//从数组中删除最后一个元素，返回删除的元素
	public E removeLast() {
		return remove(size);
	}
	
	//从数组中删除元素e
	public void removeElement(E e) {
		for(int i = 0;i<size;++i)
			while(data[i].equals(e) && i < size)
				data[i] = data[i+1];
	}
	//将数组内的元素转换为String对象返回
	public String toString() {
		StringBuilder res = new StringBuilder();
		res.append(String.format("Array:size = %d, capacity = %d \n",size,data.length));
		res.append("[");
		for(int i = 0;i<size;++i) {
			res.append(data[i]);
			if(i != size-1)
				res.append(",");
		}
		res.append("]");
		return res.toString();
	}
	
	//打印出数组内的所有元素
	public void PrintArray() { 
		if(size == 0) {
			System.out.println("数组为空！");
			return ;
		}
			
		for(int i = 0;i<size;++i)
			System.out.print(data[i] + " ");
		System.out.println();
	}
	
}
