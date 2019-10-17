<%@ page contentType="text/html;charset=UTF-8" %>
<%! 
	public String GetMax(double x,double y)
	{
		if(x > y)
		{
			double temp = x;
			x = y;
			y = temp;
		}
		return ("大数是:" + y +",小数是" + x);
	}
%>
<%
	String dx = request.getParameter("dx");
	String dy = request.getParameter("dy");
	double x = Double.parseDouble(dx);
	double y = Double.parseDouble(dy);
%>
<html>
	<body>
		<p>被加载文件：</P>
			加载文件的接收值：dx=<%=dx%>,dy=<%=dy%>。</br>
			GetMax的调用结果为：<%=GetMax(x,y)%>
	</body>
</html>