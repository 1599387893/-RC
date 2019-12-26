<%--
  Created by IntelliJ IDEA.
  User: lenovo
  Date: 2019/12/25
  Time: 22:55
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>验证界面</title>
</head>
<body>
<%
    request.setCharacterEncoding("UTF-8");
    String[] name = new String[]{"RC","任成"};
    String[] password = new String[]{"170599245","123456"};
    String userName = request.getParameter("userName");
    String userPassword = request.getParameter("userPassword");

    for (int i = 0;i < name.length;i++) {
        if (userName.equals(name[i]) && userPassword.equals(password[i])) {
            response.sendRedirect("index.jsp");
            break;
        } else {
            response.sendRedirect("error.jsp");
            break;
        }
    }
%>
</body>
</html>