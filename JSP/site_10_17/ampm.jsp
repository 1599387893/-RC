<%@ page contentType="text/html;charset=UTF-8"%>
<%@ page import="java.util.*" %>

<html>
	<head>
		<title>JSP:FORWORD转向的页面</title>
	</head>
	<body>
		<%
			String str=rquest.getParameter("hello");
		%>
		<font size="5" color="red">
		<%=str%>
	</body>
</html>