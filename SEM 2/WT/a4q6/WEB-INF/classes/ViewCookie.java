import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.*;

public class ViewCookie extends HttpServlet {
    public void service(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException{
        Cookie c[] = req.getCookies();
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        if(c == null){
            out.print("<h1>There are no cookies to show here");
        }
        else{
            String resultString = "<table>";
            for (Cookie cookie : c) {
                resultString += "<tr><td>" + cookie.getName() + "</td><td>" + cookie.getValue() + "</td></tr>";
            }

            resultString += "</table>";

            out.print(resultString);
        }

        out.print("<a href='/a4q6'>Click here to go back</a>");
    }
}
