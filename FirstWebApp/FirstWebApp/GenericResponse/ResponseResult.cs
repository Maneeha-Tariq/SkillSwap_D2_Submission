namespace FirstWebApp.GenericResponse
{
    public class ResponseResult<T>
    {
        public int Code { get; set; }
        public string? Message { get; set; }   
        public T? Data { get; set; }
        public static ResponseResult<T> Success(int code,string msg,T? data)
        {
            return new ResponseResult<T>
            {
                Code = code,
                Message = msg,
                Data = data
            };
        }
        public static ResponseResult<T> Failure(int code, string msg, T? data)
        {
            return new ResponseResult<T>
            {
                Code = code,
                Message = msg,
                Data = data
            };
        }
    }
}
