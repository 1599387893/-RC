<%@ page contentType="text/html;charset=UTF-8" %>
<%@ page import="java.util.*" %>
<html>
	<head>
		<title>JSP:FORWORD使用示例</title>
	</head>
	
	<body>
		<p>这是第一个页面的输出</P>
		<%
			if(Calendar.HOUR>Calendar.AM){
		%>
			<jsp:forword page="ampm.jsp">
				<jsp:param name="hello" value="Good a.m!." />
			</jsp:forword>
		<%
			}else{
		%>
			<jsp:forword page="ampm.jsp">
				<jsp:param name="hello" value="Good a.m.!"/>
			</jsp:forword>
		<% 
			}
		%>
	</body>
</html>
