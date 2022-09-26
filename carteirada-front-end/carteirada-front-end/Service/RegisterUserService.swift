//
//  RegisterUserService.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 22/09/22.
//

import Foundation
import Alamofire

class RegisterUserService {
    func postUser(login: String, email: String, password: String, sucess: @escaping (User)-> Void,error: @escaping (Error)-> Void) {
        var parameter =  [String:Any]()
        parameter["login"] = login
        parameter["email"] = email
        parameter["password"] = password
        
        NetworkService.request(url: "https://carteirada-back-end-production.up.railway.app/user", method: .post, params: parameter, obj: User.self) { result in
            sucess(result)
        } error: { e in
            error(e)
        }
    }
}
