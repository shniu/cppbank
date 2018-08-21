//
// Created by niushaohan on 2018/8/20.
//

/**
 * 1.
 */

#ifndef FLUENTCPP_SERVER_HPP
#define FLUENTCPP_SERVER_HPP

namespace tinyhttp {
    /**
     * 客户端发起请求的辅助函数
     *
     * @param hostname
     * @param port
     * @return
     */
    int open_clientfd(char * hostname, int port);

    /**
     * 服务端监听辅助函数
     */
    int open_listenfd(int port);

    /**
     * Server startup function
     */
    void main();
}

#endif //FLUENTCPP_SERVER_HPP
