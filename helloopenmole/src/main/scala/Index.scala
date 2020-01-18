import scalatags.Text.all._
import better.files._

object Index {
  val htmlFrag: String = "<!DOCTYPE html>" + html(
    head(
      meta(charset := "utf-8"),
    ),
    body(
      h1("Hello world!")
    )
  )

  def main(args: Array[String]): Unit = {
    println(htmlFrag)
    File("index.html").overwrite(htmlFrag)
  }
}
