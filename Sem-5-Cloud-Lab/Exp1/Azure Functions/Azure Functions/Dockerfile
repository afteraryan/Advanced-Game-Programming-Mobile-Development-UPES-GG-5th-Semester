#See https://aka.ms/containerfastmode to understand how Visual Studio uses this Dockerfile to build your images for faster debugging.

FROM mcr.microsoft.com/azure-functions/dotnet:4 AS base
WORKDIR /home/site/wwwroot
EXPOSE 80

FROM mcr.microsoft.com/dotnet/sdk:6.0 AS build
WORKDIR /src
COPY ["Azure Functions/Azure Functions.csproj", "Azure Functions/"]
RUN dotnet restore "Azure Functions/Azure Functions.csproj"
COPY . .
WORKDIR "/src/Azure Functions"
RUN dotnet build "Azure Functions.csproj" -c Release -o /app/build

FROM build AS publish
RUN dotnet publish "Azure Functions.csproj" -c Release -o /app/publish /p:UseAppHost=false

FROM base AS final
WORKDIR /home/site/wwwroot
COPY --from=publish /app/publish .
ENV AzureWebJobsScriptRoot=/home/site/wwwroot \
    AzureFunctionsJobHost__Logging__Console__IsEnabled=true