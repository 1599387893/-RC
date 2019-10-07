						<%-- 测试JSP中的switch case语句 --%>
<%@ page language="java"  contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>

<%! int day=3; %>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Control Statements</title>
	</head>
	
	<body>
		<h3>Switch...case</h3>
		<%
			switch(day){
				case 0:
					out.println("星期天");
					break;
				case 1:
					out.println("星期一");
					break;
				case 2:
					out.println("星期二");
					break;
				case 3:
					out.println("星期三");
					break;
				case 4:
					out.println("星期四");
					break;
				case 5:
					out.println("星期五");
					break;
				default:
					out.println("星期六");
					break;
			}
		%>
	</body>
</html>










						<%-- 测试JSP中的if else语句 --%>
<%-- <%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %> 
<%! int day=3; %>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Control statements</title>
	</head>
	
	<body>
		<h3>IF...ELSE实例</h3>
		
		<%	if(day==1 | day==7){ %>
			<p>Today is weekend</p>
		<% } else { %>
			<p>今天不是周末</p>
		<% } %>
	
	</body>
</html>
--%>


