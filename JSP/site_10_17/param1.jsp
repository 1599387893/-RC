<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<head>
	<title>这是include动作标记示例</title>
</head>
<body bgcolor = "cyan">
	<%
		double dx = 3.14,dy = 4.3;
	%>
	<p>主页面信息：加载param2.jsp文件，求两个数的最大值：</p>
	开始加载...
	
	<jsp:include page = "param2.jsp">
		<jsp:param name = "dx" value = "<%=dx%>" />
		<jsp:param name = "dy" value = "<%=dy%>" />
	</jsp:include>
	
	<p>主页信息：加载完毕！</p>
</body>

</html>