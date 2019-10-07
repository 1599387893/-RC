						<%--FOR 循环测试 --%>
<%--
<%@ page language="java" contentType="text/html; charset=UTF-8" 
	pageEncoding="UTF-8"%>
<%! int fontSize; %>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Loop Test</title>
	</head>
	
	<body>
		<h3>FOR循环测试</h3>
		<% for(fontSize=1; fontSize<=5;fontSize++){ %>
			<font color="green" size="<%= fontSize %>" >
			RC's Page
			</font><br/>
		<% } %>
	</body>
</html>
--%>
						<%--WHILE 循环测试 --%>
<%@ page language="java" contentType="text/html;charset=UTF-8" 
	pageEncoding="UTF-8"%>

<%! int fontSize = 0; %>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>loop test</title>
	</head>
	
	<body>
		<h3>While循环实例 </h3>
		<% while(fontSize<6) { %>
			<font color="green" size="<%= fontSize %>">
			RC'S page
			</font>
			</br>
		<% fontSize++ ;%>
		<%	} %>
	</body>
</html>
