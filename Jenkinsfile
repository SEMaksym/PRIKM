pipeline {
    agent any
	
    
    stages {
        stage('Start') {
		   mqttNotification brokerUrl :'tcp://test.mosquitto.org',
		      topic : 'labs/build',
			  message : '${BUILD_RESULT}'
		   
            steps {
                echo 'Lab_2: nginx/custom'
            } 
        }
        
        stage('Auto Image Build') {
            steps {
                sh "docker build -t prikm:latest ." 
                sh "docker tag prikm semaksym/prikm:latest" 
                sh "docker tag prikm semaksym/prikm:$BUILD_NUMBER" 
            } 
        }
        
        stage('Push to registry') {
            steps {
                echo 'Start pushing'
                withDockerRegistry([ credentialsId: "dockerhub_ID", url: "" ])
                {
                    echo 'access granted'
                    sh "docker push semaksym/prikm:latest"
                    sh "docker push semaksym/prikm:$BUILD_NUMBER"
                    echo 'push success'
                }
            }
        }
        
        stage('Auto deploy image'){
            steps{
                sh "docker stop \$(docker ps -q) || true"
                sh "docker container prune --force"
                sh "docker image prune --force"
                sh "docker run -d -p 80:80 semaksym/prikm"
            } 
        } 
    } 
}
