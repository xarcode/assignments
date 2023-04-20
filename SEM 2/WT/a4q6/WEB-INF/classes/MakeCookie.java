import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.*;

/**
 * MakeCookie
 */
public class MakeCookie extends HttpServlet{
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Cookie c = new Cookie(req.getParameter("name"), req.getParameter("value"));
        resp.addCookie(c);
        resp.sendRedirect("viewcookie");
    }
}   