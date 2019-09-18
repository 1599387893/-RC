public class Array<E> {
	private E[] data;
	private int size;
	
	//���캯��
	public Array(int capacity) {
		data = (E[])new Object[capacity];
		size = 0;
	}
	
	//�޲ι��캯��
	public Array() {
		this(10);
	}
	
	//��ȡ���������
	public int getCapacity() {
		return data.length;
	}
	
	//��ȡ�����е�Ԫ�ظ���
	public int getSize() {
		return  size;
	}
	
	//���������Ƿ�Ϊ��
	public boolean isEmpty() {
		return (size==0);
	}
	
	//��index������λ�ò���һ����Ԫ��e
	public void add(int index,E e) {
		
		if(size == data.length)
			System.out.println("����������");
		if(index < 0 || index > size)
			System.out.println("����Խ�磡");
		
		for(int i = size -1 ; i >= index; i--)
			data[i+1] = data[i];
		data[index] = e;
		size++;	
	}
	
	//������Ԫ�غ����һ����Ԫ��
	public void addLast(E e) {
		add(size,e);
	}
	
	//������Ԫ��ǰ���һ����Ԫ��
	public void addFrist(E e) {
		add(0,e);
	}
	
	//��ȡindex����λ�õ�Ԫ��
	public E Get(int index) {
		if(index >= size || index < 0)
			System.out.println("index����Խ�磡");
		return data[index];
	}
	//�޸�index����λ�õ�Ԫ��Ϊe
	public void set(int index,E e) {
		if(index > data.length || index < 0)
			System.out.println("index����Խ�磡");
		data[index] = e;
	}
	
	//�����������Ƿ���Ԫ��e
	public boolean contains(E e) {
		if(find(e) != -1)
			return true;
		return false;
	}
	//���������е�Ԫ��e���ڵ����������������Ԫ��e���򷵻�-1
	public int find(E e) {
		for(int i = 0;i<size;++i)
			if(data[i].equals(e))
				return i;
		return -1;
	}
	
	//��������ɾ��indexλ�õ�Ԫ�أ�����ɾ����Ԫ��
	public E remove(int index) {
		if(index < 0 || index > data.length)
			System.out.println("index����Խ�磡");
		E ret = data[index];
		for(int i = index-1; i >= 0;--i)
			data[i] = data[i+1];
		return ret;
	}
	
	//��������ɾ����һ��Ԫ�أ�����ɾ����Ԫ��
	public E removeFrist() {
		return remove(0);
	}
	
	//��������ɾ�����һ��Ԫ�أ�����ɾ����Ԫ��
	public E removeLast() {
		return remove(size);
	}
	
	//��������ɾ��Ԫ��e
	public void removeElement(E e) {
		for(int i = 0;i<size;++i)
			while(data[i].equals(e) && i < size)
				data[i] = data[i+1];
	}
	//�������ڵ�Ԫ��ת��ΪString���󷵻�
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
	
	//��ӡ�������ڵ�����Ԫ��
	public void PrintArray() { 
		if(size == 0) {
			System.out.println("����Ϊ�գ�");
			return ;
		}
			
		for(int i = 0;i<size;++i)
			System.out.print(data[i] + " ");
		System.out.println();
	}
	
}
