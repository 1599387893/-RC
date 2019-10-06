import java.util.*;
import java.text.*;

public class Date{
	public static void main(String[] args){
		/*
		Date d1 = new Data(2019,9,10);
		Date d2 = new Data(2019,9,9);
		
		System.out.println("d1 < d2 "+d2.after(d1));
		System.out.println("d1 < d2 "+d2.before(d1));
		*/
		
		//Date date = new Date();
		//System.out.println(date.toString());
	
		//Date dNow = new Date();
		//SimpleDateFormat ft = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
		
		//System.out.println("当前时间为："+ft.format(dNow));
		
		/*
		Date date = new Date();
		
		System.out.printf("全部日期和时间信息：%tc%n",date);
		System.out.printf("年-月-日格式: %tF%n",date);
		System.out.printf("月/日/年格式：%tD%n",date);
		*/
		   // 初始化 Date 对象
     Date date = new Date();
 
     //c的使用  
    System.out.printf("全部日期和时间信息：%tc%n",date);          
    //f的使用  
    System.out.printf("年-月-日格式：%tF%n",date);  
    //d的使用  
    System.out.printf("月/日/年格式：%tD%n",date);  
    //r的使用  
    System.out.printf("HH:MM:SS PM格式（12时制）：%tr%n",date);  
    //t的使用  
    System.out.printf("HH:MM:SS格式（24时制）：%tT%n",date);  
    //R的使用  
    System.out.printf("HH:MM格式（24时制）：%tR",date);
	
	
	
	
	
	
	
	
	
	
	}
}