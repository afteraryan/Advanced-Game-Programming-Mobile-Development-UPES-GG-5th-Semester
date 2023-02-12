using System;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Host;
using Microsoft.Extensions.Logging;

namespace Functions2
{
    public class Function2
    {
        [FunctionName("Function2")]
        public void Run([QueueTrigger("myqueue-items", Connection = "Emulator")]string myQueueItem, ILogger log)
        {
            log.LogInformation($"C# Queue trigger function processed: {myQueueItem}");
        }
    }
}
